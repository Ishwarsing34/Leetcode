class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>>arr;


        for(int i=0;i<nums.size();i++)
        {
            arr.push_back({nums[i],i});
        }


        sort(arr.begin(),arr.end());


        int st = 0 , en = nums.size()-1;


        while(st<en){

            int ans = arr[st].first + arr[en].first;

            if(ans==target) return {arr[st].second,arr[en].second};
            else if(ans < target) st++;
            else en--;
        }


        return {-1,-1};


        
    }
};