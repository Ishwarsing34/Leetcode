class Solution {
public:
    bool makeEqual(vector<string>& words) {

        int n = words.size();

        map<int, int> mp;

        for (string word : words) {

            for (char ch : word) {

                mp[ch]++;
            }
        }

        for (string word : words) {
            for (char ch : word) {

                if (mp[ch] % n != 0)
                    return false;
            }
        }

        return true;
    }
};