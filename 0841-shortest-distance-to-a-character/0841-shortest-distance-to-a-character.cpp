class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(s[i] == c){
                ans.push_back(i);
            }
        }

        vector<int>res(n);

        for(int i=0;i<n;i++)
        {
            if(s[i]==c){
                res[i] = 0;
            }else{
               
               int val = INT_MAX;
               for(int j=0;j<ans.size();j++){
                   
                   val = min(val,abs(i-ans[j]));
               }

               res[i] = val;

            }
        }

        return res;
    }
};