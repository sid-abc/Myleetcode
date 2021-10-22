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
    vector<int> nextLargerNodes(ListNode* head) {
        if(head->next==NULL)
            return {0};
        
        vector <int> ans;
        ListNode *p = head;
        ListNode *t = head;
        while(p->next) {
            t = p->next;
            while(t) {
                if(t->val > p->val) {
                    ans.push_back(t->val);
                    break;
                }
                else
                    t = t->next;
            }
            if(t==NULL)
                ans.push_back(0);
            p = p->next;
        }
        ans.push_back(0);
        
        return ans;
    }
};