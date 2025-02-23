class Solution {
    bool allzeros(vector<int>&cnt)
    {
        for(auto i:cnt)
        {
            if(i != 0) return  false;
        }

        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();

        vector<int>cnt(26,0);
        vector<int>ans;

        int k = p.size();

        for(int i=0;i<k;i++)
        {
            cnt[p[i]-'a']++;
        }


        int i = 0, j = 0;

        while(j < n)
        {
            cnt[s[j]-'a']--;

            if(j-i+1 == k){

                if(allzeros(cnt)){
                    ans.push_back(i);
                }

                cnt[s[i]-'a']++;
                i++;
            }

            j++;
        }

        return ans;
    }
};