class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        int mx = 0;

        for(int i=0;i<n;i++){
           
            if(nums[i] == 0) cnt = 0;
            else cnt++;

            mx = max(cnt,mx);

        }

        return mx;
    }
};