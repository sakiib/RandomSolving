class MinStack {
public:
    stack <int> all, minima;
    MinStack() {
        
    }
    
    void push(int val) {
        all.push(val);
        if (minima.size() == 0 || minima.top() >= val) {
             minima.push(val);
        }
    }
    
    void pop() {
        if (all.top() == minima.top()) {
            minima.pop();
        }
        all.pop();
    }
    
    int top() {
        assert((int)all.size() > 0);
        return all.top();
    }
    
    int getMin() {
        assert((int)minima.size() > 0);
        return minima.top();
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
