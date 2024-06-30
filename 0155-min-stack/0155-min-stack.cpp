class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        long long x = (long long)val;
        if(st.empty()){
            st.push(x);
            mini = x;
        } 
        else{
            if(mini <= x) {
                st.push(x);
            }
            else{
                st.push(2*x-mini);    //This is always lesser than val
                mini = x;
            }
        }
    }
    
    void pop() {
        if(st.top() < mini){    //A fake value is present, make sure to retrieve the old min
            mini = 2*mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mini) return (int)mini;
        else return (int)st.top();
    }
    
    int getMin() {
        return (int)mini;
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