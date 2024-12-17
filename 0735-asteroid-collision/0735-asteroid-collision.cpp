class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
         stack<int>st;
        for(int &num : a){


            while(!st.empty() && num < 0 && st.top() > 0)
            {
                int sum = num + st.top();

                if(sum < 0){
                    st.pop();
                }else if(sum > 0){
                    num = 0;
                }else{
                    //sum == 0
                    st.pop();
                    num = 0;
                }
            }

            if(num != 0)
            {
                st.push(num);
            }
        }

        int s = st.size();

        vector<int>result(s);

        int i = s-1;
        while(!st.empty())
        {
            result[i] = st.top();
            st.pop();
            i--;
        }

        return result;
    }
};