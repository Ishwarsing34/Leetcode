class Solution {
public:
    string decodeMessage(string key, string message) {

        unordered_map<char, char> mp;

        char curr = 'a';

        for (char ch : key) {

            if (ch == ' ')
                continue;
            else if (mp.find(ch) == mp.end()) {
                mp[ch] = curr;
                curr++;
            }
        }

        string res = "";

        for (char ch : message) {

            if (ch == ' ')
                res += ' ';
            else {
                res += mp[ch];
            }
        }

        return res;
    }
};