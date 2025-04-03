class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        int num  = 1;
        int i = 0;
         
         while(i<n && k > 0){


            if(arr[i] == num){
                i++;
            }else{

                k--;
            }

            num++;
         }


         while(k--){
            num++;
         }

         return num-1;
    }

};