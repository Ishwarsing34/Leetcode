class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<int,int>mp;
        int res = 0, maxFreq = 0;
        int i = 0;
        for(int j=0;j<n;j++){
            mp[s[j]]++;

            maxFreq = max(maxFreq,mp[s[j]]);

            while( j-i+1 - maxFreq > k){
                mp[s[i]]--;
                i++;
                // if(mp[])
            }

            res = max(res,j-i+1);
        }

        return res;
    }
};