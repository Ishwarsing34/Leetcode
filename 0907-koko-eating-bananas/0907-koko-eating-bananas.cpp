class Solution {

private:
    int isPossible(vector<int>& piles, int mid, int h, int n) {

        int hour = 0;

        for (int i = 0; i < n; i++) {

             hour += (piles[i] + mid - 1) / mid;


            if(hour > h) return false;

        }

        return hour<=h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(piles, mid, h, n)) {

                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};