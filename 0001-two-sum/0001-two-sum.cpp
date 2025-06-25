class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>>arr;

        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());


        int n = arr.size();

        int s = 0 , e = n - 1;

        while(s < e){

            int sum = arr[s].first + arr[e].first;

            if(sum == target) return {arr[s].second,arr[e].second};
            else if(sum < target) s++;
            else e--;
        }

        return {};
    }
};