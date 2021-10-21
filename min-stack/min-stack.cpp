class MinStack {
public:
    stack <int> stk;
    stack <int> mins;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(mins.empty()) {
            stk.push(val);
            mins.push(val);
        }
        else if(val<=mins.top()) {
            mins.push(val);
            stk.push(val);
        }
        else 
            stk.push(val);
    }
    
    void pop() {
        if(stk.top()==mins.top()) {
            stk.pop();
            mins.pop();
        }
        else 
            stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */