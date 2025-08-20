class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end()); 

        int n = s.size();
        int i = 0;
        string lastword = "";

        while (i < n) {
            while (i < n && s[i] == ' ') i++;   

            while (i < n && s[i] != ' ') {      
                lastword += s[i];
                i++;
            }

            break; 
        }

        return lastword.size();
    }
};
