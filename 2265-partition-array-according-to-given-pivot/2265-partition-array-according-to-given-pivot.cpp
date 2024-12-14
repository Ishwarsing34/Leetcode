class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>result(n);
        int left = 0;

        vector<int>equal;
        vector<int>greater;

        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
            {
                result[left] = nums[i];
                left++;
            }else if(nums[i]>pivot)
            {
                greater.push_back(nums[i]);
            }else{
                equal.push_back(nums[i]);
            }
        }


        for(auto num : equal)
        {
            result[left] = num;
            left++;
        }

        for(auto nums : greater)
        {
            result[left] = nums;
            left++;
        }

        return result;

    }
};