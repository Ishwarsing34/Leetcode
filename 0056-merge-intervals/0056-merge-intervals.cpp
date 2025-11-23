class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        

        vector<vector<int>>ans;

        int n = inter.size();


        sort(inter.begin(),inter.end());

        
        for(int i=0;i<n;)
        {
            int st = inter[i][0];
            int en = inter[i][1];

            int j = i + 1;

            while(j<n && en >= inter[j][0])
            {
                en = max(en,inter[j][1]);
                j++;
            }

            ans.push_back({st,en});

            i=j;
        }


        return ans;
    }
};