class Solution {
public:
    long long maximumScore(vector<int>& nums) {

        int n = nums.size();

        vector<long long> prefSum(n), suffMin(n);

      
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

       
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], (long long)nums[i]);
        }

        long long maxScore = LLONG_MIN;


        for (int i = 0; i < n - 1; i++) {
            long long score = prefSum[i] - suffMin[i + 1];
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};
