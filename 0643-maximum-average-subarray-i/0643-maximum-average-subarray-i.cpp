class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double cur_sum =0,max_sum=0;

        for(int i=0;i<k;i++){
            cur_sum+=nums[i];
        }

        max_sum = cur_sum;

        for(int st=1,en=k;en<n;st++,en++){
            cur_sum-=nums[st-1];
            cur_sum+=nums[en];

            max_sum= max(max_sum,cur_sum);
        }
        return max_sum/k;
    }
};