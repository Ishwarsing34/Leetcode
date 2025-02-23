class Solution {
    bool allzero(vector<int>&counter){

       for(auto i : counter)
       {
         if(i != 0) return false;
       }

        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>counter(26,0);
        vector<int>ans;

        int n = s.size();


        for(int i=0;i<p.size();i++)
        {
            counter[p[i] - 'a']++;
        }

        int k = p.size();

        int i = 0;
        int j = 0;

        while(j<n)
        {
            counter[s[j]-'a']--;


            if(j-i+1 == k){

                if(allzero(counter)){
                    ans.push_back(i);
                }

                counter[s[i]-'a']++;
                i++;
            }


            j++;
        }

        return ans;
    }
};