class MyCircularQueue {
private:
    int size, front, rear;
    int *Q;
public:
    MyCircularQueue(int k) {
        size = k;
        front = rear = -1;
        Q = new int[size];
        
    }
    
    bool enQueue(int value) {
        if(!isFull()) {
            rear = (rear + 1) % size;
            Q[rear] = value;
            if(front==-1)
                front = 0;
            return true;
        }
        return false;
        
    }
    
    bool deQueue() {
        if(!isEmpty()) {
            if(front==rear)
                front = rear = -1;
            else 
                front = (front + 1)%size;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(!isEmpty()) {
            int x = Q[front];
            return x;
        }
        return -1;
    }
    
    int Rear() {
        if(!isEmpty()) {
            int x = Q[rear];
            return x;
        }
        return -1;
    }
    
    bool isEmpty() {
        if(front==rear && rear==-1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((rear + 1) % size == front)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */