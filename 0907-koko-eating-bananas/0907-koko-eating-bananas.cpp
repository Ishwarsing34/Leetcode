class Solution {
    bool isPossible(vector<int>& piles, int mid, int h) {
        int hour = 0;

        for (int i = 0; i < piles.size(); i++) {
            hour += (piles[i] + mid - 1) / mid;

            if (hour > h)
                return false;
        }

        return hour <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while (l <= high) {
            int mid = l + (high - l) / 2;

            if (isPossible(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};