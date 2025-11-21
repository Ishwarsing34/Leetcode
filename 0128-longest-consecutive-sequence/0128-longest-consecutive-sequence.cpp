class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        

        sort(nums.begin(),nums.end());

        int n = nums.size();
        if(n == 0) return 0;
        int cnt = 0;
        int longest = 1;
        int lastSmall = INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(nums[i]-1 == lastSmall){
                cnt+=1;
                lastSmall = nums[i];
            }else if(lastSmall != nums[i] ){
                cnt = 1;
                lastSmall = nums[i];
            }

            longest = max(cnt,longest);
        }


        return longest;
    }
};