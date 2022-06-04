/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
                    //head   chead      
        unordered_map<Node*, Node*> mp;
        Node *chead = new Node(head->val);
        mp[head] = chead;
        Node *p = head->next, *q = chead;
        
        while(p) {
            q->next = new Node(p->val);
            mp[p] = q->next;
            p = p->next;
            q = q->next;
        }
        
        p = head, q = chead;
        while(p) {
            q->random = mp[p->random];
            p = p->next;
            q = q->next;
        }
        
        return chead;
    }
};