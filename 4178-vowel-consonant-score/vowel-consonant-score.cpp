class Solution {
public:
    int vowelConsonantScore(string s) {
        

         int conso = 0;
         int vowel = 0;

         for(int i=0;i<s.size();i++){

            char ch = s[i];

            if( isspace(ch) || isdigit(ch) ) continue;


            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'e'){
                vowel++;
            }else{
                conso++;
            }
         }

         
         if(conso > 0){

            int ans = floor(vowel/conso);
            return ans;
         }else{
            return 0;
         }
    }
};