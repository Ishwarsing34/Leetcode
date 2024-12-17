class MinStack {
    stack<long long>st;
    long min = LLONG_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long value =(long long) val;
        if(st.empty())
        {
            st.push(value);
            min = value;
        }else{
            if(min>value)
            {
                st.push(2*value - min);
                min = value;
            }else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        long long  x = st.top();
        st.pop();

        if(min>x)
        {
            min = 2*min - x;
        }
    }
    
    int top() {
        long long x = st.top();

        if(x>min) return x;
        else return min;
    }
    
    int getMin() {
        return min;
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