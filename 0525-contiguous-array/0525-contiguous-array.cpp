class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        mp[0] = -1;

        int curr_sum = 0;
        int len = 0;

        for(int i=0;i<n;i++) {

            curr_sum+= nums[i] == 0 ? -1 : 1;

            if(mp.find(curr_sum) != mp.end()){
                
                len = max(len,i-mp[curr_sum]);
            }else{
                
                mp[curr_sum] = i;
            }
        }

        return len;

    }
};