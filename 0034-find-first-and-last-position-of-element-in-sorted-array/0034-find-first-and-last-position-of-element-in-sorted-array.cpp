class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size() - 1;
        int start = 0;
        int end = n;

        int first_pos = -1;
        int last_pos = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                first_pos = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }


        start = 0;
        end = n;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                last_pos = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        ans.push_back(first_pos);
        ans.push_back(last_pos);

        return ans;
    }
};