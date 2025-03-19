class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<=2*n;j++){
               int ind = j%n;

               if(nums[i]<nums[ind]){
                   ans[i] = nums[ind];
                    break;
               }
            }
        }

        return ans;
    }
};