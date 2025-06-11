class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int total_pts = 0;

        for (int i = 0; i < n; i++) {
            total_pts += cardPoints[i];
        }

        int i = 0, j = 0;

        int sum = 0;
        int min_sum = INT_MAX;

        while (j < n) {

            sum += cardPoints[j];

            while (j - i + 1 > n - k) {

                sum -= cardPoints[i];
                i++;
            }
            if (j - i + 1 == n - k) {
                min_sum = min(min_sum, sum);
            }
            j++;
        }

        return total_pts - min_sum;
    }
};