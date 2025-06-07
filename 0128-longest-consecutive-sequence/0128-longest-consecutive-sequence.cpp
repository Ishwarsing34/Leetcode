class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longest = 1;
        unordered_set<int> st;

        if(nums.size() == 0) return 0;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        for (auto it : st) {

            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {

                    cnt++;
                    x = x + 1;
                }

                longest = max(cnt, longest);
            }
        }

        return longest;
    }
};