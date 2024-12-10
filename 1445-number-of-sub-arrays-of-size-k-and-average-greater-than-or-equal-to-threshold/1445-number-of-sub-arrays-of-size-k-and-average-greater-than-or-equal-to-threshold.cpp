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
        for (int i = 0; i < k; i++) {

            sum += nums[i];
        }

        if (sum / k >= t)
            cnt++;

        for (int st = 1, en = k; en < n; st++, en++) {

            sum -= nums[st - 1];
            sum += nums[en];

            if (sum / k >= t)
                cnt++;
        }

        return cnt;
    }
};