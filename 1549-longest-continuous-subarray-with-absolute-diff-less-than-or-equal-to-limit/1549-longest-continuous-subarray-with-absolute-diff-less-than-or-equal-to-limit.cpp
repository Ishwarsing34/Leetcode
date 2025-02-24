class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        multiset<int>st;
        int n = nums.size();

        int i = 0, j = 0, maxLen = 0;

        while(j < n){

            st.insert(nums[j]);

            while(*st.rbegin() - *st.begin() > k){
                 st.erase(st.find(nums[i]));
                i++;
            }

            maxLen = max(j-i+1,maxLen);

            j++;
        }

        return maxLen;
    }
};