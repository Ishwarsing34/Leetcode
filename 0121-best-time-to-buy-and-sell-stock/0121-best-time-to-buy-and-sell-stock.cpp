class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyP=prices[0];
        int maxP=0;
        for(int i=0;i<prices.size();i++)
        {
            if(buyP>prices[i])
            {
                buyP=prices[i];
            }
            else
            {
                int current=prices[i]-buyP;
                maxP=max(maxP,current);
            }
        }

        return maxP;
    }
};