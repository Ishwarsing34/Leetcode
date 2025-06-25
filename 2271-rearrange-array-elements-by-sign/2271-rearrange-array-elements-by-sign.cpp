class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>neg,pos,res;

        for(int i=0;i<n;i++){
            if(nums[i]>=0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        };

        int i = 0 , j = 0;

        while(i < pos.size() && j < neg.size())
        {
              res.push_back(pos[i++]);
              res.push_back(neg[j++]);
        }

        while(i < pos.size()){
            res.push_back(pos[i]);
            i++;
        }
        while(j < neg.size()){
            res.push_back(neg[j++]);
        }

        return res;
    }
};