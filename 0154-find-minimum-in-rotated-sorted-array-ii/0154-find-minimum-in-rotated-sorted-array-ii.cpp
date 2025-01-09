class Solution {

    int findPivot(vector<int>nums,int low, int high) {

        while(low < high){

            while(low < high  && nums[low] == nums[low+1]){
                low++;
            }

            while(low < high && nums[high] == nums[high-1]){
                high--;
            }

            int mid = low + (high - low)/2;

            if(nums[mid]>nums[high]){
                low = mid + 1;
            }else{
                high = mid;
            }

        }

        return high;
    }
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n-1;


        int pivot = findPivot(nums,low,high);

        return nums[pivot];
    }
};