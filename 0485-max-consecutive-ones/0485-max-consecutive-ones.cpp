class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();

        int maxx = 0;

        int cnt = 0;

        for(int i=0;i<n;i++)
        {
           if(nums[i] == 1 ){
            cnt++;
           }
            if(nums[i]== 0){
                cnt = 0;
            }

            maxx = max(cnt,maxx);
        }

        return maxx;
    }
};