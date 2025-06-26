class Solution {
    bool isgood(string a){
        if(a.size() < 3) return false;

        set<int>st;

        for(int i=0;i<a.size();i++)
        {
            st.insert(a[i]);
        }

        return st.size() == 3;
    }
public:
    int countGoodSubstrings(string s) {
        
        int n = s.size();
        int cnt = 0;

        for(int i=0;i<=n-3;i++){
            
            if(isgood(s.substr(i,3))){
                cnt++;
            }
        }

        return cnt;
    }
};