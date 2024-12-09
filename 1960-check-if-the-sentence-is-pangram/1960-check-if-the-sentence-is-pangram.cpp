class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int>arr(26,0);
        int cnt  = 0;

        for(char& ch : s){
          int  idx = ch - 'a';

            if(arr[idx] == 0)
            {
                arr[idx]++;
                cnt++;
            }
        }

        return true ? (cnt == 26) : false;
    }
};