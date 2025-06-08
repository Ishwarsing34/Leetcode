class Solution {

    int squaredigits(int n) {

        int sq = 0;
        while (n) {

            int last_dig = n % 10;
            sq += last_dig * last_dig;
            n /= 10;
        }

        return sq;
    }

public:
    bool isHappy(int n) {
        // base conditions
        if (n == 1)
            return true;
            if(n == 7) return true;

            unordered_set<int>st;
        
        while(st.find(n) == st.end()){

            st.insert(n);
            n = squaredigits(n);

            if(n == 1) return true;
        }

        return false;

    }
};