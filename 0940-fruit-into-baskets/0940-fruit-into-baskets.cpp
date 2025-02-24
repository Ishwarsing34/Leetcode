class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int,int>mp;

        int n  = f.size();


        int right = 0;
        int left = 0;

        int maxxi = 0;

        for(int right = 0;right < n;right++)
        {
            mp[f[right]]++;

            while(mp.size()>2){
                mp[f[left]]--;
                if(mp[f[left]] == 0){
                    mp.erase(f[left]);
                }
                left++;
            }

            maxxi = max(right-left+1,maxxi);
        }

        return maxxi;
    }
};