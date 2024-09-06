class Solution {
private:
    bool isVowel(char c)
    {
        c = tolower(c);
        return (c =='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    string reverseVowels(string s) {
        int n = s.size();
        string ans="";


        for(int i=0;i<n;i++) {
             if(isVowel(s[i])){
                ans.push_back(s[i]);
             }
        }

        reverse(ans.begin(),ans.end());

        int j=0;

        for(int i=0;i<n;i++) {
            if(isVowel(s[i])){
                s[i] = ans[j];
                j++;
            }
        }

        return s;
    }
};