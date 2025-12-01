class Solution {

    bool maxDays(vector<int>& day, int mid, int m, int k) {
        int consec_cnt = 0;
        int bq_cnt = 0;

        for (int i = 0; i < day.size(); i++) {
            if (day[i] <= mid)
                consec_cnt++;
            else
                consec_cnt = 0;

            if (consec_cnt == k) {
                bq_cnt++;
                consec_cnt = 0;
            }
        }

        return bq_cnt >= m;
    }

public:
    int minDays(vector<int>& day, int m, int k) {

        int n = day.size();

        int low = 1;
        int high = *max_element(day.begin(), day.end());
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (maxDays(day, mid, m, k)) {
                ans = mid;
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};