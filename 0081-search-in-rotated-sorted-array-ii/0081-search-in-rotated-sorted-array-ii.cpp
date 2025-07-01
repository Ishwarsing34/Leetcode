class Solution {

    int findMin(vector<int>&nums)
    {
        int n = nums.size();

        int low = 0 , high = n-1;

        while(low < high)
        {
           

            while(low < high && nums[low] == nums[low+1]) low++;
            while(low < high && nums[high] == nums[high-1]) high--;
             int mid = low + (high-low)/2;

            if(nums[mid] > nums[high]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return high;
    }

    int search(int l, int r , vector<int>&nums,int target)
    {
        int low = l;
        int high = r;
        int idx = -1;

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(nums[mid] == target){
                idx = mid;
                break;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return idx;
    }
public:

    bool search(vector<int>& nums, int target) {
        

        int pivot = findMin(nums);
        
        int n = nums.size();

        int idx = -1;

        idx = search(0,pivot-1,nums,target);

        if(idx != -1) return true;

        idx = search(pivot,n-1,nums,target);

        return idx == -1 ? false : true;
    }
};