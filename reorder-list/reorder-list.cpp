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
    void reorderList(ListNode* head) {
        if(!head->next)
            return;
        
        ListNode *curr = head;
        while(curr && curr->next && curr->next->next) {
            ListNode *q = NULL, *p = curr;
            while(p->next) {
                q = p;
                p = p->next;   
            }
            q->next = NULL;
            p->next = curr->next;
            curr->next = p;
            
            if(curr->next->next)
                curr = curr->next->next;
            else
                break;
        }
        
    }
};