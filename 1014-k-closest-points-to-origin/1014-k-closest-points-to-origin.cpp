class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {

        priority_queue<pair<int, pair<int, int>>> pq;

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int num = arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1];
            pq.push({num, {arr[i][0], arr[i][1]}});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {

         ans.push_back({pq.top().second.first, pq.top().second.second});


            pq.pop();
        }

        return ans;
    }
};