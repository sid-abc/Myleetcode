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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p = list1;
        int i;
        for(i=0;i<a-1;i++)
            p = p->next;
        ListNode *q = p->next;
        for(int j=i+1;j<b;j++)
            q = q->next;
        
        ListNode *f = list2;
        while(f->next)
            f = f->next;
        f->next = q->next;
        p->next = list2;
        
        return list1;
    }
};