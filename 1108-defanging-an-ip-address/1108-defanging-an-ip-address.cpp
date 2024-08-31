class Solution {
public:
    string defangIPaddr(string add) {
        int n = add.size();
        int i = 0;
        string ans = "";

        for(char &ch : add) {
            if(ch == '.')
            {
                ans+="[.]";
            } else {
                ans+=ch;
            }
        }
        return ans;

        
    }
};