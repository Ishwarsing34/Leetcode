class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int sum = 0;

        unordered_map<int,int>mp;
        
        mp[0] = 1;
        int n = nums.size();

        int cnt = 0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

            int rem = sum % k;

            if(rem < 0){
                rem = rem + k;
            };


            if(mp.find(rem) != mp.end()){

                cnt+=mp[rem];
            }

            if(mp.find(rem) == mp.end())
            {
                mp[rem] = 1;
            }else{
                mp[rem]++;
            }
        }

        return cnt;


    }
};