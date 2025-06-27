class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        int M = 1e9 + 7;

        stack<int>st;

        vector<int>NSR(n,n);
        vector<int>NSL(n,-1);


        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            NSR[i] = st.empty() ? n : st.top();
            st.push(i);
        }


        while(!st.empty())
        {
            st.pop();
        }

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

             NSL[i] = st.empty() ? -1 : st.top();
             st.push(i);
        }
     

       int sum = 0;

        for(int i=0;i<n;i++)
        {
            int left = i - NSL[i];
            int right = NSR[i] - i;

            long long totalsum = ((long long )left * right)%M ;
            long long total = ((long long)arr[i] * totalsum)%M;

            sum = (sum + total)%M;

        }

        return sum;
    }
};