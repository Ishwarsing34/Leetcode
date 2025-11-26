class Solution {

    int atmost(string s,int k){

        unordered_map<int,int>mp;

        int n = s.size();


        int i = 0 , j = 0;

        int stringCnt = 0;

        while(j<n)
        {
            mp[s[j]]++;

            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);

                i++;
            }

            stringCnt += (j-i+1);
            j++;

        }

        return stringCnt;
    }
public:
    int numberOfSubstrings(string s) {
        
        int k = 3;

        return atmost(s,k)- atmost(s,k-1);
    }
};