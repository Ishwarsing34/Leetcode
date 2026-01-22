class Solution {
    void solve(vector<int>&nums, int target,int sum,int &count,int ind){

        if(ind == nums.size()){

            if(sum == target){
                count++;
            }
            return;
        }


        solve(nums,target,sum+nums[ind],count,ind+1);
        solve(nums,target,sum-nums[ind],count,ind+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        

        int sum = 0;

        int count = 0;


        solve(nums,target,sum,count,0);


        return count;
    }
};