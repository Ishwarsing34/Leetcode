class Solution {
    bool isPossible(vector<int>& bloom, int mid, int k, int m) {
        int consec_cnt = 0;
        int bq_cnt = 0;

        for (int i = 0; i < bloom.size(); i++) {
            if (bloom[i] <= mid)
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
    int minDays(vector<int>& bloom, int m, int k) {

        int start = 1;
        int end = *max_element(bloom.begin(), bloom.end());

        int min_days = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isPossible(bloom, mid, k, m)) {
                min_days = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return min_days;
    }
};