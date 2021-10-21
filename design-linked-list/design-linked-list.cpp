struct Node {
    int data;
    Node *next;
};

class MyLinkedList {
private:
    Node *head;
public:
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        if(index<0 || index > length()-1)
            return -1;
        Node *p = head;
        for(int i=0;i<index;i++)
            p = p->next;
        return p->data;
    }
    
    void addAtHead(int val) {
        Node *t = new Node;
        t->data = val;
        t->next = NULL;
        if(head==NULL)
            head = t;
        else {
            t->next = head;
            head = t;
        }
    }
    
    void addAtTail(int val) {
        Node *t = new Node;
        t->data = val;
        t->next = NULL;
        if(head==NULL)
            head = t;
        else {
            Node *p = head;
            while(p->next) p = p->next;
            p->next = t;
        }
    }
    
    void addAtIndex(int index, int val) {
        Node *t, *p = head;
        if(index<0 || index > length())
            return;
        
        t = new Node;
        t->data = val;
        t->next = NULL;
        
        if(index==0) {
            t->next = head;
            head = t;
        }
        
        else if(index==length()) {
            while(p->next) p=p->next;
            p->next = t;
        }
        
        else {
            for(int i=0;i<index-1;i++)
                p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>length()-1)
            return;
        if(index==0) {
            Node *p = head;
            head= head->next;
            delete p;
        }
        else {
            Node *p = head, *q = NULL;
            for(int i=0;i<index;i++) {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            delete p;
        }
    }
    
    int length() {
        Node *p = head;
        int len = 0;
        while(p) {
            len++;
            p = p->next;
        }
        return len;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */