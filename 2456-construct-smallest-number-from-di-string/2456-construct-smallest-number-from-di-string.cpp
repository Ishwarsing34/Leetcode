class Solution {
    bool check(string &v, string &pattern) {
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 'I' && v[i] < v[i + 1]) continue;
            else if (pattern[i] == 'D' && v[i] > v[i + 1]) continue;
            else return false;
        }
        return true;
    }

    string number(string &v, string &pattern, int ind) {
        if (ind == pattern.size()) {
            if (check(v, pattern)) {
                return v;
            }
            return "";  
        }

        for (int i = ind; i < v.size(); i++) {
            swap(v[i], v[ind]);
            string res = number(v, pattern, ind + 1); 
            swap(v[i], v[ind]);
            if (!res.empty()) return res; 
        }
        return "";
    }

public:
    string smallestNumber(string pattern) {
        string v = "";  
        for (int i = 1; i <= pattern.size() + 1; i++) {
            v.push_back('0' + i);
        }
        return number(v, pattern, 0);
    }
};
