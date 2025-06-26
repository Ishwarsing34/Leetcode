class Solution {
    bool isValid(string &s,int maxLet)
    {
        map<char,int>mpp;

        for(auto i : s)
        {
            mpp[i]++;
        }

        return mpp.size() <= maxLet;
    }
public:
    int maxFreq(string s, int maxLet, int minsize, int maxsize) {
        

        int n = s.size();
        map<string,int>mp;
        int maxi = 0;

        for(int i=0;i<=n-minsize;i++)
        {
            string curr = s.substr(i,minsize);

            if(isValid(curr,maxLet))
            {
                mp[curr]++;
                maxi = max(maxi,mp[curr]);
            }
        }

        return maxi;
    }

};