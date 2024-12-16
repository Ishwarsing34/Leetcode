class Solution {
    bool isValid(string cur, int maxLet) {
        map<char, int> mp;

        for (char c : cur) {
            mp[c]++;
        }

        return mp.size() <= maxLet;
    }

public:
    int maxFreq(string s, int maxLet, int minSize, int maxSize) {
        int n = s.size();

        map<string, int> mp;
        int maxx = 0;
        if (n == 0 || maxLet == 0) return 0;
        
        for (int i = 0; i < n - minSize + 1; i++) {
            string cur = s.substr(i, minSize);  // Fix: Correct substring extraction
            if (isValid(cur, maxLet)) {
                mp[cur]++;
                maxx = max(maxx, mp[cur]);
            }
        }
        return maxx;
    }
};
