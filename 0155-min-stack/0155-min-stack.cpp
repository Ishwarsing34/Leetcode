class MinStack {

    stack<long long> st;
    long  min;

public:
    MinStack() {
         min = LLONG_MAX;

     
           
    }

    void push(int val) {
        long long v = (long long)val;
        if (st.empty()) {
            min = v;
            st.push(v);
        } else {

            if (v < min) {
                st.push(2 * v  - min);
                min = v;
            } else {
                st.push(v);
            }
        }
    }

    void pop() {

        if (st.empty())
            return;

        if (st.top() < min) {
            min = (2 * min * 1LL - st.top());
            st.pop();
        } else {
            st.pop();
        }
    }

    int top() {

        if (st.empty())
            return -1;

        long long el = st.top();
        if(el < min) return  min;

        return el;
    }

    int getMin() { return (int)min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */