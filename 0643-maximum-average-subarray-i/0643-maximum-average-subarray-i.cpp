class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double max_sum = 0;
        double curr_sum = 0;

        for(int i=0;i<k;i++){
            curr_sum+=nums[i];
        }

        max_sum = curr_sum;

        for(int st=1,en=k;en<n;st++,en++)
        {
            curr_sum-=nums[st-1];
            curr_sum+=nums[en];

            max_sum = max(max_sum,curr_sum);
        }

        return max_sum/k;
    }
};