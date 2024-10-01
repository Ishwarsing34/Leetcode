class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long xor_r = 0;

        for(int &num : nums)
        {
            xor_r^=num;
        }

        int grpA=0;
        int grpB=0;

        int mask = (xor_r) & (-xor_r);

        for(int i=0;i<nums.size();i++)
        {
            if(mask & (nums[i])){
                grpA ^= nums[i];
            } else {
                grpB ^= nums[i];
            }
            
        }

        return {grpA,grpB};
    }
};