class Solution {
    void solve(int ind, vector<string>&ans, string &temp, vector<string>&mapping,string digits){

        if(temp.size() == digits.size()){
            ans.push_back(temp);
            return;
        }


        int digit = digits[ind] - '0';

        for(char curr : mapping[digit]){

            temp.push_back(curr);
            solve(ind+1,ans,temp,mapping,digits);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        if(digits.empty()) return {};
        string temp ="";

        vector<string> mapping = {
            {},                   // 0 (not used)
            {},                   // 1 (not used)
            {'a', 'b', 'c'},      // 2
            {'d', 'e', 'f'},      // 3
            {'g', 'h', 'i'},      // 4
            {'j', 'k', 'l'},      // 5
            {'m', 'n', 'o'},      // 6
            {'p', 'q', 'r', 's'}, // 7
            {'t', 'u', 'v'},      // 8
            {'w', 'x', 'y', 'z'}  // 9
        };


        solve(0,ans,temp,mapping,digits);

        return ans;
    }
};