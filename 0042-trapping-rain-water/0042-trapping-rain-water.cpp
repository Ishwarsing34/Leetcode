class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();


        int prefMax[n];
        int sufMax[n];
       
        prefMax[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            
            prefMax[i] = max(prefMax[i-1],nums[i]);
        }

        sufMax[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            sufMax[i] = max(nums[i],sufMax[i+1]);
        }

        int trap = 0;

        for(int i=0;i<n;i++)
        {
            trap += min(prefMax[i],sufMax[i]) - nums[i];
        }

        return trap;
    }
};