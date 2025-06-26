class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double maxi = 0;
        double n = nums.size();
        double curr_sum = 0;

        for(int i=0;i<k;i++)
        {
            curr_sum += nums[i];
        }

        maxi = curr_sum;

        for(int st=1,en=k;en<n;st++,en++)
        {
            curr_sum -= nums[st-1];
            curr_sum += nums[en];

            maxi = max(curr_sum,maxi);
        }

        return maxi/k;



    }
};