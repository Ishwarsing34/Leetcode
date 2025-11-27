class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();

        stack<int>st;

        vector<int>ans(n);


        for(int i=2*n;i>=0;i--)
        {
            int ind = i%n;

            while(!st.empty() && st.top() <= nums[ind])
            {
                st.pop();
            }


            if(i < n)
            {
                ans[i] = st.empty() ? -1 : st.top();
            }

            st.push(nums[ind]);
        }
        
        return ans;

    }
};