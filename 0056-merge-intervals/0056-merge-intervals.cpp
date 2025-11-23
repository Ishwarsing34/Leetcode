class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        

        vector<vector<int>>ans;

        sort(intervals.begin(),intervals.end());


        for(auto inter : intervals)
        {
            if(ans.empty() || ans.back()[1] < inter[0] ){
                ans.push_back(inter);
            }else{
                ans.back()[1] = max(ans.back()[1],inter[1]);
            }
        }


        return ans;
    }
};