class Solution {
public:
    string sortString(string s) {
        
        int n = s.size();

     vector<int>cnt(26,0);

        for(int i=0;i<n;i++)
        {
            cnt[s[i]-'a']++;
        }


        string res = "";

        while(res.size() < n)
        {
            for(int i=0;i<26;i++)
            {
                if(cnt[i] > 0){
                    res.push_back('a' + i);
                    cnt[i]--;
                }
            }

            for(int i=25;i>=0;i--){
                
                if(cnt[i] > 0){
                    res.push_back('a'+i);
                    cnt[i]--;
                }
            }
        }

        return res;



    }
};