class Solution {

    int canMake(vector<int>& bloomDay, int mid, int k) {
        int bouque_count = 0;
        int consecutive_cnt = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                consecutive_cnt++;
            } else {
                consecutive_cnt = 0;
            }

            if (consecutive_cnt == k) {
                bouque_count++;
                consecutive_cnt = 0;
            }
        }

        return bouque_count;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int start = 0;
        int end_day = *max_element(begin(bloomDay), end(bloomDay));
        int minDays = -1;

        while (start <= end_day) {
            int mid = start + (end_day - start) / 2;

            if (canMake(bloomDay, mid, k) >= m) {
                minDays = mid;
                end_day = mid - 1;

            } else {
                start = mid + 1;
            }
        }

        return minDays;
    }
};