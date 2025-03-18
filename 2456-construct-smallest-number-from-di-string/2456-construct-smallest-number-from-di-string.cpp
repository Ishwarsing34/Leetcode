class Solution {
public:
    string smallestNumber(string pattern) {

        int ind = 0;
        string res = "";
        int n = pattern.size();
        vector<int>stack(n + 1); /// regular stack doesnt allow indexing
            for (int i = 0; i <= n; i++) {

            stack[ind++] = i + 1;

            if (i == n || pattern[i] == 'I') {

                while (ind > 0) {
                    res += to_string(stack[--ind]);
                }
            }
        }

        return res;
    }
};