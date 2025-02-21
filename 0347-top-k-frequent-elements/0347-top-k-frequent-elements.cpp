class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;


           for(auto i=mp.begin();i!=mp.end();i++)
           {
            pq.push({i->second,i->first});

            if(pq.size() > k){
                pq.pop();
            }
           }


           vector<int>ans;

           while(!pq.empty())
           {
              int el = pq.top().second;
              ans.push_back(el);
              pq.pop();
           }

           return ans;
    }
};