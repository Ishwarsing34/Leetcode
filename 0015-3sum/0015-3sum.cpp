class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            int a = nums[i];
            int k  = -a;

            int s = i+1 , e = n -1;

            while(s < e)
            {
                if(nums[s] + nums[e] == k){
                    ans.push_back({nums[i],nums[s],nums[e]});

                    while(s < e && nums[s] == nums[s+1]) s++;
                    while(s < e && nums[e] == nums[e-1]) e--;

                    s++,e--;
                }else if(nums[s] + nums[e] < k) s++;
                else e--;
            } 

            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }

        return ans;
    }
};