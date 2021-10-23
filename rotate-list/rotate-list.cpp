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
    int length(ListNode *p) {
        int len = 0;
        while(p) {
            len++;
            p = p->next;
        }
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        
        int t = k % length(head);
        while(t--) {
            ListNode *p = head, *q = NULL;
            while(p->next) {
                q = p;
                p = p->next;
            }
            q->next = NULL;
            p->next = head;
            head = p;
        }
        
        return head;
    }
};