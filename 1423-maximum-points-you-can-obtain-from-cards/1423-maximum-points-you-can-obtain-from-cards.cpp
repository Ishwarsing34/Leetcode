class Solution {
public:
    int maxScore(vector<int>& card, int k) {

        int maxSum = 0;
        int n = card.size();
        int left_sum = 0, right_sum = 0;

        for (int i = 0; i < k; i++) {

            left_sum += card[i];
        }

        maxSum = left_sum;
        int right = n - 1;

        for (int i = k - 1; i >= 0; i--) {

            left_sum -= card[i];
            right_sum += card[right];
            right--;

            maxSum = max(maxSum, left_sum + right_sum);
        }

        return maxSum;
    }
};