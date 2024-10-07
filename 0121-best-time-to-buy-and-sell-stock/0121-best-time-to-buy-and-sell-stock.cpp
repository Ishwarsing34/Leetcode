class Solution {
public:
    int maxProfit(vector<int>& p) {
        int curr_p = p[0];
        int maxiP = 0;

        for(int i=0;i<p.size();i++)
        {
            if(p[i]<curr_p)
            {
                curr_p = p[i];
            } else{
                int current = p[i] - curr_p;
                 maxiP = max(maxiP,current);
            }

        }
        return maxiP;
    }
};