class Solution {
    int atMost(vector<int>&nums, int k)
    {

         int n = nums.size();
         int i =0 , j = 0;

         int niceArr = 0;

         if(k < 0) return 0;


         int cnt  = 0;


         while(j<n){

            if(nums[j] % 2 != 0) cnt++;

            while(cnt > k){
                
                if(nums[i]%2 != 0){
                    cnt--;
                }

                i++;
            }

            niceArr += (j-i+1);

            j++;
         }


         return niceArr;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        

         return atMost(nums,k) - atMost(nums,k-1);
    }
};