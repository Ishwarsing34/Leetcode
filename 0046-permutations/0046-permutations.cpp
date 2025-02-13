class Solution {

    void permutations(vector<int>&nums,vector<vector<int>>&ans,int ind){

        if(ind == nums.size()){
            ans.push_back(nums);
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            permutations(nums,ans,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int ind = 0;
        
        permutations(nums,ans,ind);

        return ans;
    }
};