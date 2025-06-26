class Solution {

    bool isVowel(char C){
    char ch = tolower(C);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    
  }
public:
    string reverseVowels(string s) {
        int n = s.size();
        vector<char>res;

        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i])){
                res.push_back(s[i]);
            }
        }

        reverse(res.begin(),res.end());
        
        int j = 0;
        for(int i=0;i<n;i++){
            
            if(isVowel(s[i])){
                s[i] = res[j];
                j++;
            }
        }

        return s;


    }
};