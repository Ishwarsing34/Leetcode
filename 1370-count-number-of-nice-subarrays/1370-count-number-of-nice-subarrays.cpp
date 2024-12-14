class Solution {
    int atmost(vector<int>&nums,int k){

        long long right = 0, left = 0, sum = 0, ans = 0;

        for(right=0;right<nums.size();right++){

            if(nums[right]%2 != 0) k--;

            while( left <= right && k<0){
                 if(nums[left]%2 != 0) k++;
                 left++;
            }

            ans+= right - left + 1;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};