class Solution {
public:
    int compress(vector<char>& chars) {
        int  n = chars.size();
        int i = 0;
        int ind = 0;

        while(i<n){

            int cnt = 0;
            int curr = chars[i];

            while(i<n && chars[i] == curr){
                i++;
                cnt++;
            }

            chars[ind] = curr;
            ind++;


            if(cnt>1){

                string str = to_string(cnt);

                for(auto it : str){

                    chars[ind] = it;
                    ind++;
                }
            }
        }

        return ind;
    }
};