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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode *dummy = new ListNode;
        ListNode *curr = dummy;
        for(int i=0; i<lists.size(); i++)
            if(lists[i])
                pq.push(make_pair(lists[i]->val, lists[i]));
        while(!pq.empty()) {
            ListNode *p = pq.top().second;
            pq.pop();
            curr->next = p;
            curr = p;
            p = p->next;
            if(p)
                pq.push(make_pair(p->val, p));
        }
        return dummy->next;
    }
};