class MinStack {
    private:
      stack<pair<int,int>>st;

public:
    MinStack() {
        
    }
    //TC = o(n)
    //sc = (2*N)-->storing the pair Data struct
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }else{
            st.push({val,min(val,st.top().second)});
        }
    }
    
    void pop() {
         st.pop();
    }
    
    int top() {
      int el = st.top().first;
      return el;
    }
    
    int getMin() {
        int el = st.top().second;
        return el;
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