class Solution {
    int getCnt(vector<int>& position, int mid, int k) {

        int cnt = 1;
        int pos = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (pos + mid <= position[i]) {
                cnt++;
                pos = position[i];
            }
        }

        return cnt;
    }

public:
    int maxDistance(vector<int>& position, int k) {
        int n = position.size();
        sort(position.begin(), position.end());

        int start = 1;
        int result = 0;
        int end = position[n-1] - position[0];

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (getCnt(position, mid, k) < k) {
                end = mid - 1;
            } else {

                result = mid;
                start = mid + 1;

                
            }
        }

        return result;
    }
};