class Solution {
private:
    bool check(const string &v, const string &pattern) {
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 'I' && v[i] < v[i + 1])
                continue;
            else if (pattern[i] == 'D' && v[i] > v[i + 1])
                continue;
            else
                return false;
        }
        return true;
    }

public:
    string smallestNumber(string pattern) {
        int n = pattern.size();

       
        string v = "";
        for (int i = 1; i <= n + 1; i++) {
            v.push_back('0' + i); //use to convert int i into corresponding val
            // '0' + 2 = 48 + 2 = 50  --> 50 corrsponds to 2;
        }

       
        bool found = false;
        while (!found) {
            if (check(v, pattern)) {
                found = true; 
            } else {
                next_permutation(v.begin(), v.end()); 
            }
        }

        return v;
    }
};
