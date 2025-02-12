class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int>tempY(n);
        vector<int>tempN(n);


        for(int i=0;i<n;i++)
        {
            if(customers[i] == 'Y'){
                tempY[i] = 1;
            }else{
                tempY[i] = 0;
            }


            if(customers[i] == 'N'){
                tempN[i] = 1;
            }else{

                tempN[i] = 0;
            }
        }

        vector<int>pref(n),suff(n);

        pref[0] = tempN[0];

        for(int i = 1; i < n ; i++){

             pref[i] = tempN[i] + pref[i-1];
        }

        suff[n-1] = tempY[n-1];

        for(int i=n-2;i>=0;i--){

            suff[i] = suff[i+1] + tempY[i];
        }

        int minP = INT_MAX;
        int minH = 0;
        for(int i = 0; i <= n ; i++)
        {
            int penalty = 0;

            if(i > 0){
                penalty += pref[i-1];
            }
            if(i<n){
                penalty+=suff[i];
            }


           if(penalty < minP){
              minP = penalty;
              minH = i;
           }

        }

        return minH;
    }
};