class Solution {
private:
    string reversed(string res)
    {
        int n = res.size();

        int start = 0;
        int end = n-1;

        while(start < end)
        {
            swap(res[start],res[end]);
            start++;
            end--;
        }

        return res;
    }
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
   //keep smaller digits at the start and get rid of larger ones
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && k>0 && st.top() -'0' > num[i] - '0')
            { 
                k--;
                st.pop();

            }
            st.push(num[i]);
        }

        while(k>0)
        {
            st.pop();
            k--;
        }

        string res = "";

        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }

        res = reversed(res);

        while(res.size()>0 && res[0] == '0')
        {
            res.erase(res.begin());
        }

        return res.empty() ? "0" : res;
    }
};