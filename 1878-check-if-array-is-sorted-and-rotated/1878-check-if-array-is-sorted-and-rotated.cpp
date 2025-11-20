class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();

        int cnt = 0;

        if(nums[0] < nums[n-1]) cnt++;

        for(int i=1;i<n;i++)
        {
            if(nums[i-1] > nums[i]) cnt++;
        }

        return cnt<=1;
    }
};