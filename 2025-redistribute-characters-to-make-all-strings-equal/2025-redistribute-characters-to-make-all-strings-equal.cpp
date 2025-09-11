class Solution {
public:
    bool makeEqual(vector<string>& words) {
         int n = words.size();

         unordered_map<char,int>mp;


         for(int i=0;i<n;i++)
         {
            int m = words[i].size();

            for(int j=0;j<m;j++)
            {
                mp[words[i][j]]++;
            }
         }


         
         for(auto it:mp)
         {
               if(it.second % n != 0) return false;
         }

         return true;
    }
};