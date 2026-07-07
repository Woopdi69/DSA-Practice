class MyQueue {
private:
    stack<int> stk;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        vector<int> temp;
        while(!stk.empty()){
            temp.push_back(stk.top());
            stk.pop();
        }

        stk.push(x);
        for(int i = temp.size()-1; i >= 0; i--){
            stk.push(temp[i]);
        }

        cout << endl;
    }
    
    int pop() {
        int val = stk.top();
        stk.pop();

        return val;
    }
    
    int peek() {
        return stk.top();
    }
    
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */