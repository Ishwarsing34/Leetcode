class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<pair<int,int>>arr;

        for(int i=0;i<n;i++){

            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());

        int s = 0;
        int e = arr.size()-1;

        while(s<e)
        {
            int sum = arr[s].first + arr[e].first;
 
            if(target == sum) return {arr[s].second,arr[e].second};
            else if(sum < target)s++;
            else e--;
        }

        return {-1,-1};
    }
};