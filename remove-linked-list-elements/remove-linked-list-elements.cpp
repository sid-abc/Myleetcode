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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *p = head, *q = head;
        while(p) {
            if(p==head && p->val==val) {
                head = head->next;
                delete p;
                q = head;
                p = head?head->next :NULL;
            }
            else if(q==head && q->val==val) {
                head = head->next;
                delete q;
                q = head;
                p = head->next;
            }
            else if(p->val==val) {
                q->next = p->next;
                delete p;
                p = q->next;
            }
            else {
                q = p;
                p = p->next;
            }
        }
        if(head!=NULL && head->val == val)
            head = NULL;
        
        return head;
    }
};