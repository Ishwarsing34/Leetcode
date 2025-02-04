class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();

        string ans = "";
        int ind = -1;

        for (int i = 0; i < n; i++) {
            ans.push_back(word[i]);

            if (word[i] == ch) {
                ind = i;
                reverse(ans.begin(), ans.end());
                break;
            }
        }
        if(ind != -1){
        for (int i = ind + 1; i < n; i++) {

            ans.push_back(word[i]);
        }


        }
        
        return ans;
    }
};