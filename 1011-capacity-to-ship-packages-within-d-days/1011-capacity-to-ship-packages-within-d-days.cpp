class Solution {
    bool canShipped(vector<int>& weights, int mid, int days) {

        int sum = 0;
        int min_Day = 1;

        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];

            if (sum > mid) {
                sum = 0;
                min_Day++;
                sum = weights[i];
            }

          
        }

        return min_Day <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();

        int low = *max_element(weights.begin(),weights.end());
       

        int maxsum = 0;

        for (int i = 0; i < n; i++) {
            maxsum += weights[i];
        }

        int high = maxsum;

        int minDays = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canShipped(weights, mid, days)) {

                minDays = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return minDays;
    }
};