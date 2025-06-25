class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;

        int longest  = 0 ;

        while(j<n)
        {
            if(nums[j] == 0) k--;

            while(k<0){
                
                if(nums[i] == 0) k++;
                i++;

            }

            longest = max(j-i+1,longest);
            j++;
        }

        return longest;
    }
};