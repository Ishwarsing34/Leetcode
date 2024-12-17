class CustomStack {

    //LAZY PROPAGATION METHOD
public: 
    vector<int>st;
    vector<int>increments;
    int n;

    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(st.size() < n) {
            st.push_back(x);
            increments.push_back(0); //no incas ofnow
        }
    }
    
    int pop() {
        if(st.size() == 0) return -1;

        int idx = st.size() - 1;  //st.back() idx of top elemnt
        if(idx > 0){
            increments[idx-1] += increments[idx]; //lazy prop method
        }

        int top_val = st[idx] + increments[idx];

        st.pop_back();
        increments.pop_back();

        return top_val;
    }
    
    void increment(int k, int val) {
        //k's value can be greater than st.size();

        int idx = min(k,(int)st.size()) - 1;

        if(idx >= 0){
            increments[idx] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */