class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
    
        map<vector<int>,int>mp;
        int ans = 0;
        int n = dom.size();

        for(int i=0;i<n;i++) {
           
           sort(dom[i].begin(),dom[i].end());
            mp[dom[i]]++;
        }

        for(auto i:mp)
        {
            int n=i.second;
            ans+=n*(n-1)/2;

        }

        return ans;


        
    }
};