class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        string ans = "";

        int i=0;
        int j=0;

        while(i<n && j<m)
        {
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }

        while(i<n){
            ans.push_back(word1[i++]);
        }

        while(j<m){
            ans.push_back(word2[j++]);
        }

        return ans;
    }
};