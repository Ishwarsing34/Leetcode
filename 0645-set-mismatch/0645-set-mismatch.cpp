class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        vector<int>ans(2);

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }


        for(auto& it:mp)
        {
            if(it.second==2)
            {
                ans[0] = it.first;
                break;
            }
        }

        for(int i=1;i<n+1;i++)
        {
            if(mp[i] == 0)
            {
                ans[1] = i;
                break;
            }
        }

        return ans;
    }
};