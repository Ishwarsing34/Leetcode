class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<pair<int,int>>arr;

        for(int i=0;i<n;i++)
        {
            arr.push_back({nums[i],i});
        }


        sort(arr.begin(),arr.end());

        int st = 0 , en = n - 1;

        while(st < en)
        {
            int sum = arr[st].first + arr[en].first;

            if(sum == target) return {arr[st].second,arr[en].second};
            else if(sum < target) st++;
            else en--;
        }

        return {-1,-1};
    }
};