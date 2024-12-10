class Solution {
    // bool checkAvg(vector<int> nums, int i, int j, int threshold, int k) {
    //     int sum = 0;

    //     for (int k = i; k <= j; k++) {
    //         sum += nums[k];
    //     };

    //     return (sum / k >= threshold);
    // }

public:
    int numOfSubarrays(vector<int>& nums, int k, int t) {
        int n = nums.size();
        int sum = 0;
        int cnt = 0;

        int i = 0;
        int j = 0;

        while (j < n) {
            sum += nums[j];
            while (j - i + 1 == k) {
                if (sum / k >= t) {
                    cnt++;
                }
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return cnt;
    }
};