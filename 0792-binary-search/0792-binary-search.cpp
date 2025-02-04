class Solution {
public:

   int binary(vector<int>nums, int st, int en, int target){
        

        if(st>en) return -1;
        int mid = st + (en - st)/2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] < target){
            return binary(nums,mid+1,en,target);
        }else{

            return binary(nums,st,mid-1,target);
        }
   } 
//using recursion
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int st = 0;
        int en = n-1;

        return binary(nums,st,en,target);
    }
};