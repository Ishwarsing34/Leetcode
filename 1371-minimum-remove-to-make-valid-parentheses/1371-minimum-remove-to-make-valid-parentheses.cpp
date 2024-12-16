class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();

        string result = "";
        int open = 0;

        for(int i=0;i<n;i++){

            if(s[i] >= 'a' && s[i] <= 'z'){
                result.push_back(s[i]);
            }else if(s[i] == '('){
                open++;
                result.push_back(s[i]);
            }else if(open > 0){
                open--;
                result.push_back(s[i]);
            }
        }

        string final = "";

        int close = 0;

        for(int i = result.size()-1;i>=0;i--){

            if(result[i] >= 'a' && result[i] <= 'z'){
                final.push_back(result[i]);
            }else if(result[i] == ')'){
                close++;
                final.push_back(result[i]);
            }else if(close > 0){
                close--;
                final.push_back(result[i]);
            }
        }

        reverse(final.begin(),final.end());

        return final;
    }
};