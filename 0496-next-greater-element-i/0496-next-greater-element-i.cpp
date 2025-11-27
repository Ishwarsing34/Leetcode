class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {

        map<int, int> mp;

        int n = nums.size();

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() < nums[i]) {
                st.pop();
            }

            mp[nums[i]] = st.empty() ? -1 : st.top();

            st.push(nums[i]);
        }

        for(int i=0;i<nums1.size();i++)
        {
            nums1[i] = mp[nums1[i]];
        }


        return nums1;
    }
};