class MyStack {
private:
   vector<int>arr;
   
public:
    MyStack() {
        
    }
    
    void push(int x) {
       
        arr.push_back(x);
    }
    
    int pop() {
       if(arr.size()== 0) return -1;

       int ans = arr.back();
        arr.pop_back();
       return ans;
    }
    
    int top() {
        if(arr.size() == 0) return -1;

         int ans = arr.back();
       
       return ans;
    }
    
    bool empty() {
        return arr.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */