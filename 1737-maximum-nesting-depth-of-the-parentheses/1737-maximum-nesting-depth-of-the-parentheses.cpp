class Solution {
public:
    int maxDepth(string s) {
        int maxx = 0;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')')
                cnt--;

            maxx = max(cnt, maxx);
        }

        return maxx;
    }
};