class Solution {
   void count(vector<int>&temp, int ind, int n, int &ans){
        if(ind >= temp.size() ){
            ans++;
            return;
        }

        for(int i=ind;i<temp.size();i++){

            swap(temp[i],temp[ind]);

            if( temp[ind] % (ind+1) == 0 || (ind+1)% temp[ind] == 0){
                count(temp,ind+1,n,ans);

            }

            swap(temp[i],temp[ind]);
        }
    }
public:
    int countArrangement(int n) {
        int ind = 0;
        vector<int>temp;
        int ans = 0;

        for(int i=1;i<=n;i++){
            temp.push_back(i);
        }

        count(temp,ind,n,ans);

        return ans;
    }
};