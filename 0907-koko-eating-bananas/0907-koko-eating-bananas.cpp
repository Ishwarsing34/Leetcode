class Solution {

    bool kokoEats(vector<int>& piles, int mid, int h) {

        int hour = 0;

        for (int i = 0; i < piles.size(); i++) {
            // Calculate hours required for the current pile
            hour += (piles[i] + mid - 1) / mid;

          
            if (hour > h)
                return false;
        }

        return hour <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int result = 0;
        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (kokoEats(piles, mid, h)) {

                result = mid;
                high = mid - 1;
            } else {

                low = mid + 1;
            }
        }

        return result;
    }
};