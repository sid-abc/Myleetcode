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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next)
            return NULL;
        
        ListNode *p = head;
        int pos = length(head) - n + 1;
        if(pos==1) {
            head = head->next;
            delete p;
        }
        else {
            for(int i=1;i<pos-1;i++)
                p = p->next;
            ListNode *q = p->next;
            p->next = q->next;
            delete q;
        }
        
        return head;
    }
};