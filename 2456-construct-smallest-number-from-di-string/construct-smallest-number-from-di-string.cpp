class Solution {
    bool isValid(string &pattern, string &temp) {
        int n = pattern.size();
        for (int i = 0; i < n; i++) {
            if (pattern[i] == 'I' && temp[i] > temp[i + 1]) return false;
            if (pattern[i] == 'D' && temp[i] < temp[i + 1]) return false;
        }
        return true;
    }

    bool solve(string &pattern, string &temp, int ind, string &ans) {
        int n = pattern.size();

      
        if (ind == temp.size()) {
            if (isValid(pattern, temp)) {
                ans = temp;
                return true; 
            }
            return false;
        }

        for (int i = ind; i < temp.size(); i++) {
            swap(temp[ind], temp[i]);

            
            if (solve(pattern, temp, ind + 1, ans))
                return true;

            swap(temp[ind], temp[i]); 
        }

        return false;
    }

public:
    string smallestNumber(string pattern) {
        int n = pattern.size();

        string temp = "";
        for (int i = 1; i <= n + 1; i++) {
            temp += char(i + '0'); 
        }

        string ans = "";
        solve(pattern, temp, 0, ans);
        return ans;
    }
};
