class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();

        int i = n - 1;

        while (num[i] == '0') {

            i--;
        }

        string ans = num.substr(0, i + 1);

        return ans;
    }
};