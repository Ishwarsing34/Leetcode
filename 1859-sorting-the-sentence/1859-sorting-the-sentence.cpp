class Solution {
public:
    string sortSentence(string s) {
        int n = s.size();
        vector<string>v(10);
        string word="";
        string ans="";

        for(int i=0;i<n;i++){
           
            if(isdigit(s[i]))
            {
               v[s[i]-'0'] = word + " ";
               word="";
               i++;
            }
            else word+=s[i];
        }

        for(auto x:v){
           ans+=x;
        }
        ans.pop_back();
        return ans;
    }
};