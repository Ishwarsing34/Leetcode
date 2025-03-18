class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();

        stack<int> st;

        for (auto& num : ast) {
            while (!st.empty() && num < 0 && st.top() > 0) {
                int sum = st.top() + num;

                if (sum < 0) {

                    st.pop();

                } else if (sum > 0) {
                    num = 0;
                } else {
                    st.pop();
                    num = 0;
                }
            }

            if(num!=0){
                st.push(num);
            }
        }

        int s = st.size();

        int i = s - 1;
        vector<int> res(s);

        while (!st.empty()) {
            res[i] = st.top();
            st.pop();
            i--;
        }

        return res;
    }
};