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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next)
            return head;
        
        ListNode *curr = head, *q = NULL;
        for(int i=1;i<left;i++) {
            q = curr;
            curr = curr->next;
        }
        
        ListNode *con = q, *tail = curr;
        ListNode *third = NULL;
        for(int i=left;i<=right;i++) {
            third = curr->next;
            curr->next = q;
            q = curr;
            curr = third;
        }
        
        if(con)
            con->next = q;
        else
            head = q;
        
        tail->next = curr;
        return head;
        
    }
};