class Solution {
public:
    int maxProfit(vector<int>& p) {
        int max_p = p[0];

        int max_prof = 0;

        for(int i=1;i<p.size();i++)
        {
            if(p[i] < max_p){
                max_p = p[i];
            }else{

                int price = p[i] - max_p;
                max_prof = max(max_prof,price);
            }
        }

        return max_prof;
    }
};