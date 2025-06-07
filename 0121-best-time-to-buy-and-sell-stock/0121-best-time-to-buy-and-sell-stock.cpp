class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        int curr_p = p[0];
        int max_p = 0;

        
        for(int i=0;i<p.size();i++){

            if(p[i]<curr_p){
                curr_p = p[i];
            }else{

                int profit =  p[i] - curr_p;
                max_p = max(profit,max_p);
            }
        }

        return max_p;
    }
};