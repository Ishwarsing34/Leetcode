class Solution {
    int isPossible(vector<int>&weights,int mid, int days,int n){

        int minDays = 1;
        int sum = 0;

        for(int i=0;i<n;i++){

            sum+=weights[i];

            if(sum>mid){
                minDays++;
                sum=weights[i];
            }
        }

        if(minDays<=days){
            return true;
        }

        return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int maxCap = 0;
        int result = 0;

        int ans = 0 ;

        for(int i=0;i<n;i++){
            maxCap += weights[i];
        }

        int low = *max_element(weights.begin(),weights.end());
        int high = maxCap;

        while(low<=high){

            int mid = low + (high-low)/2;

            if(isPossible(weights,mid,days,n)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    
    }
};