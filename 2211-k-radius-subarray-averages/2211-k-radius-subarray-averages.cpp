class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>result(n,-1);

        if(n < 2*k+1) return result;


        int left = 0;
        int right = 2*k;
        long long window = 0;
        int count = 2*k+1;


        int i = k;


        for(int k=left;k<=right;k++){
               window += nums[k];
        }
       
       result[i] = window/count;
       i++;
    //    left++;
       right++;

       while(right<n){

          int in = nums[right];
          int out = nums[left]; 

          window -= out;
          window += in;;

          result[i] = window/count;

          i++;
          left++;
          right++;
       }


       return result;

    }
};