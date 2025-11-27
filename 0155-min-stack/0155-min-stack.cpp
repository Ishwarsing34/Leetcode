class MinStack {

    stack<int> st;
    long long min;

public:
    MinStack() {
         min = INT_MAX;

        while (!st.empty()){
              st.pop();
        }
           
    }

    void push(int val) {

        if (st.empty()) {
            min = val;
            st.push(val);
        } else {

            if (val < min) {
                st.push(2 * val * 1LL - min);
                min = val;
            } else {
                st.push(val);
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

        int el = st.top();
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