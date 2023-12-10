class MinStack {
    stack<vector<int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push({val, st.empty() ? val : min(st.top()[1], val)});
    }
    
    void pop() {
        if(st.empty())
            return;
        st.pop();
    }
    
    int top() {
        return st.top()[0];
    }
    
    int getMin() {
        return st.top()[1];
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