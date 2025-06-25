class Solution {
public:
    int beautySum(string s) {
        int n = s.size();


   int ans  = 0;
        for(int i=0;i<n;i++){
            map<char,int>mp;
            for(int j=i;j<n;j++){
               int  maxi = INT_MIN;
               int mini = INT_MAX;
                mp[s[j]]++;

                for(auto it:mp)
                {
                    mini =min(it.second,mini);
                    maxi = max(it.second,maxi);
                }

                ans += (maxi - mini);
            }
            
        }

        return ans;
    }
};