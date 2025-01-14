
    








class Solution {
    bool canweplace(vector<int>&stalls,int dis,int k){
        //dis=mid
        int cntcows=1;//start with placing first cow at stall[0]
        int lastcow=stalls[0];//position of last cow
        for(int i=0;i<stalls.size();i++){
            if(stalls[i]-lastcow>=dis){
                cntcows++;
                lastcow=stalls[i];
            }
            if(cntcows==k) return true;
        }
        return false;
    }
  

    int aggressiveCows(vector<int> &stalls, int k) {

        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canweplace(stalls,mid,k)==true){
            ans=mid;
            low=mid+1;
            }
            else 
            high=mid-1;
        }
        return high;//low
        
    }

public:
    int maximumTastiness(vector<int>& price, int k) {
       int n=price.size();
     return aggressiveCows(price,k);

        
    }
};