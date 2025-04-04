class Solution {
public:
    int maxSum(vector<int>& nums) {

        set<int> st;
        if(nums.size() == 1) return nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]>0){
                st.insert(nums[i]);
            }
        }

        if(st.empty()){

            int ans = *max_element(nums.begin(),nums.end());
            return ans;
        }

        int sum = 0;

        for(int x : st){
            sum+=x;
        }

        return sum;
    }
};