class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string>st;

        if(s.size() < k) return false;
        
        for(int i=0;i<=n-k;i++)
        {
            st.insert(s.substr(i,k));
        }

        return st.size() == pow(2,k);
    }
};