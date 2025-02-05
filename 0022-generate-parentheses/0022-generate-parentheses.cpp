class Solution {
    void subset(int n, int left, int right, vector<string>&ans, string temp){

        if(left + right >= 2*n){
            ans.push_back(temp);
            return;
        }

        if(left<n){
           temp.push_back('(');
           subset(n,left+1,right,ans,temp);
           temp.pop_back();
        }
        if(right<left){
            temp.push_back(')');
            subset(n,left,right+1,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
      
        int left = 0;
        int right = 0;
        vector<string>ans;
        string temp = "";

       subset(n,left,right,ans,temp);

       return ans;
    }
};