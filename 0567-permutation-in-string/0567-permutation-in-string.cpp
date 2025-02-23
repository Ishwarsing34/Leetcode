class Solution {
    bool check(vector<int>&cnt)
    {
        for(auto i:cnt)
        {
            if(i!=0) return false;
        }

        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();

        int n = s2.size();


        vector<int>cnt(26,0);


        for(int i=0;i<k;i++)
        {
            cnt[s1[i]-'a']++;
        }

        int i = 0,j = 0;


        while(j < n)
        {
             cnt[s2[j]-'a']--;

             if(j-i+1 == k)
             {
                if(check(cnt))
                {
                    return true;
                }

                cnt[s2[i]-'a']++;
                i++;
             }

             j++;
        }

        return false;
    }
};