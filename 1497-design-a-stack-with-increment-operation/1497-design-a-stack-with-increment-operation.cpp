class CustomStack {
    vector<int>arr;
    int idx = -1;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        arr.resize(maxSize);
    }
    
    void push(int x) {
        if(idx+1 < maxSize){
            idx++;
            arr[idx] = x;
        }
    }
    
    int pop() {
        if(idx>=0){
            int el = arr[idx];
            idx--;
            return el;
        }else{
            return -1;
        }
    }
    
    void increment(int k, int val) {
        int limit = min(k,idx+1);

        for(int i=0;i<limit;i++){
            arr[i]+=val;
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