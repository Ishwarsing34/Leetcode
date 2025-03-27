
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int pref[n];
        int suf[n];

        pref[0] = height[0];

        for (int i = 1; i < height.size(); i++) {

            pref[i] = max(pref[i - 1], height[i]);
        }

        suf[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {

            suf[i] = max(suf[i + 1], height[i]);
        }

        int trap = 0;

        for (int i = 0; i < n; i++) {

            trap += min(pref[i], suf[i]) - height[i];
        }

        return trap;
    }
};