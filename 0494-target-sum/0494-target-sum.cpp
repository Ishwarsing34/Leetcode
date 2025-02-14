class Solution {
    int find(vector<int>&nums, int target, int ind, int sum){

          if(ind == nums.size()){

              if(sum == target){
                return 1;
              }else{
                return 0;
              }
          }


          int plus = find(nums,target,ind+1,sum+nums[ind]);
          int sub = find(nums,target,ind+1,sum-nums[ind]);


          return plus+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int ans = find(nums,target,0,0);

        return ans;
    }
};