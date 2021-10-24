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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;
        
        ListNode *before = new ListNode;
        ListNode *b = before;
        ListNode *after =  new ListNode;
        ListNode *a = after;
        
        while(head) {
            if(head->val < x) {
                b->next = head;
                b = b->next;
            }
            else {
                a->next = head;
                a = a->next;
            }
            head = head->next;
        }
        
        a->next = NULL;
        b->next = after->next;
        
        return before->next;
    }
};