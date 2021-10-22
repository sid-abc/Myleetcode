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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return NULL;
        
        ListNode *r = head, *q = head, *p = head->next;
        
        while(p) {
            if(q==head) {
                q->next = p->next;
                p->next = q;
                head = p;
                q = q->next;
                p = q? q->next: NULL;
            }
            else {
                r->next = q->next;
                q->next = p->next;
                p->next = q;
                
                r = q;
                q = q->next;
                p = q? q->next: NULL;
            }
        }
        
        return head;
    }
};