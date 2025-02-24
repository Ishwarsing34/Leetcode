class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;

        int n = s.size();
        int maxx = 0;
        int i = 0 , j = 0;

        while(j < n){

            mp[s[j]-'a']++;

            while(mp[s[j]-'a'] > 1){
                mp[s[i]-'a']--;
                i++;
            }

            maxx = max(maxx,j-i+1);
            j++;
        }

        return maxx;
    }
};