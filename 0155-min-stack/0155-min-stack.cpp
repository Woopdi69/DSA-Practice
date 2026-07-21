class MinStack {
public:
    stack<int> stk;
    stack<int> mini;
    MinStack() {
        
    }
    
    void push(int value) {
        stk.push(value);

        if(mini.empty() || value <= mini.top()){
            mini.push(value);
        }
    }
    
    void pop() {
        if(stk.top() == mini.top()){
            mini.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */