class Solution {

    void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int>temp,int ind, int target,int n)
    {

           if(ind == n ){
              
              if(target == 0){
                  ans.push_back(temp);
              }
              return;
           }


           if(arr[ind] <= target){
              
               temp.push_back(arr[ind]);
               solve(arr,ans,temp,ind,target-arr[ind],n);
               temp.pop_back();
           }

           solve(arr,ans,temp,ind+1,target,n);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        

        vector<vector<int>>ans;


        vector<int>temp;

        int n = arr.size();

        int ind = 0;

        solve(arr,ans,temp,ind,target,n);


        return ans;
    }
};