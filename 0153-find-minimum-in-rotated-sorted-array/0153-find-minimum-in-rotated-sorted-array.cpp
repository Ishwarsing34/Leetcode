class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
         if(nums.size() == 1) return nums[0];
        if(nums[0]<nums[high]) return nums[0];

        while (low <= high) {

            int mid = low + (high - low) / 2;

           if(nums[mid]>nums[high]){
                low = mid+1;
           }else{
               ans = min(ans,nums[mid]);
               high = mid-1;
           }
            
        }

        return ans;
    }
};