class Solution {
private:
    bool isVowel(char c){
        c = tolower(c);

        return(c=='a' || c=='e'|| c=='i' || c=='o' || c=='u');
    }
public:
    string sortVowels(string s) {
        int n = s.size();
        string word = s;
        string ans = "";


        for(int i=0;i<n;i++) {
           if(isVowel(s[i])){
              ans.push_back(s[i]);
           }
        };

       sort(ans.begin(),ans.end());


       int k = 0;

       for(int j=0;j<n;j++) {
        if(isVowel(s[j])){
            s[j] = ans[k];
            k++;
        }

       }

       return s;
        
    }
};  