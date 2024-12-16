class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int open = 0;
        int size = 0;


        for(char &ch : s){

            if( ch == '('){
                size++;
            }else if(size>0){
                size--;
            }else{
                open++;
            }
        }

        return open + size;
    }
};