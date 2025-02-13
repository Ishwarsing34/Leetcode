class Solution {
    bool helper(int start,int end, int a, int b,int flag,vector<int>&nums){
        if(start>end) return a>=b;

        bool sum;

        if(flag == 1){
            sum = helper(start+1,end,a+nums[start],b,2,nums) || helper(start,end-1,a+nums[end],b,2,nums);
        }else{
            sum =helper(start+1,end,a,b+nums[start],1,nums) && helper(start,end-1,a,b+nums[end],1,nums);
        }


        return sum;
    }
public:
    bool predictTheWinner(vector<int>& nums) {
         

         return helper(0,nums.size()-1,0,0,1,nums);
    }
};