class Solution {
public:
    int trap(vector<int>& h) {

        int lmaxx = 0, rmaxx = 0;

        int n = h.size();

        int left = 0, right = n - 1;

        int res = 0;

        while (left <= right) {

            if (h[left] <= h[right]) {

                if (h[left] >= lmaxx)
                    lmaxx = h[left];
                else
                    res += lmaxx - h[left];
                left++;
            } else {

                if (h[right] >= rmaxx)
                    rmaxx = h[right];
                else
                    res += rmaxx - h[right];
                right--;
            }
        }

        return res;
    }
};