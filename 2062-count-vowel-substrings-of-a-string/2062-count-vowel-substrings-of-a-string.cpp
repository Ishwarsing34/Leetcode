class Solution {
private:
     
       bool check(vector<int>& vowel){
         for(auto i:vowel){
            if(i==0) return false;
         }

         return true;
       }
public:
    int countVowelSubstrings(string word) {
        int total = 0;
        vector<int>vowel(5);
        for(int i=0;i<word.size();i++){
            vowel = vector<int>(5,0);
            for(int j=i;j<word.size();j++){
                if(word[j]=='a'){
                    vowel[0]++;
                }
                else if(word[j]=='e'){
                    vowel[1]++;
                }
                 else if(word[j]=='i'){
                    vowel[2]++;
                }
                 else if(word[j]=='o'){
                    vowel[3]++;
                }
                 else if(word[j]=='u'){
                    vowel[4]++;
                }
                else break;

                if(check(vowel)) total++;
            }
        }

        return total;
    }
};