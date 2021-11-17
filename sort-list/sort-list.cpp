/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode *a, ListNode *b) {
        ListNode *dummy = new ListNode;
        ListNode *curr = dummy;
        while(a && b) {
            if(a->val < b->val) {
                curr->next = a;
                curr = a;
                a = a->next;
            }
            else {
                curr->next = b;
                curr = b;
                b = b->next;
            }
        }
        if(a) curr->next = a;
        if(b) curr->next = b;
        
        return dummy->next;
    }
    
    ListNode* getMid(ListNode *fast) {
        ListNode *slow = NULL;
        while(fast && fast->next) {
            slow = !slow? fast: slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        return mid;
    }
};