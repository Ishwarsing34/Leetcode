class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();

        vector<int>ans(n+1);

        int low = 0;
        int high = n;
        int ind = 0;

        for(int i=0;i<n;i++){

            if(s[i] == 'I'){

                ans[ind] = low;
                low++;
                ind++;
            }else{
                ans[ind++] = high;
                high--;

            }
        }

        if(s[n-1] == 'I'){
            ans[ind] = low;
        }else{
            ans[ind] = high;
        }

        return ans;
    }
};