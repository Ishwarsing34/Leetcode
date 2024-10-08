class Solution {
public:
    bool checkIfPangram(string s) {
        int n = s.size();
        int count[26] = {0};

        for(int i=0;i<n;i++)
        {
            count[s[i]-'a']++;
        }

        for(int i=0;i<26;i++) {
            if(count[i]==0) return false;
        }

        return true;
    }
};