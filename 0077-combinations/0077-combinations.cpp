class Solution {
    void comb(int num,vector<vector<int>>&ans, vector<int>&temp, int n, int k)
    {

        if(temp.size() == k)
        {
            ans.push_back(temp);
            return ;
        }


        for(int i=num;i<=n;i++)
        {
            temp.push_back(i);
            comb(i+1,ans,temp,n,k);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;

        comb(1,ans,temp,n,k);

        return ans;
    }
};