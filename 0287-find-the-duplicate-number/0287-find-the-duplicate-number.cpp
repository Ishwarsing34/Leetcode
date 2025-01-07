class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int low = 1;
        int high = n-1,ans = 0;

        while(low<=high){
            int mid = low + (high - low)/2;

            int cnt = 0;

            for(auto &num : nums)
            {
                if(num<=mid)
                {
                    cnt++;
                }
            }

            if(cnt > mid)
            {
               ans = mid;
               high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};