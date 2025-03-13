class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        

        int cnt = 0;
        int sum = 0;

        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){

            sum+=nums[i];

            if(sum == k) cnt++;

            
            if(mp.find(sum-k) != mp.end()){

                cnt = mp[sum-k] + cnt;
            }

            if(mp.find(sum) != mp.end()){

                mp[sum]++;
            }else{
                mp[sum] = 1;
            }
        }

        return cnt;
    }
};