class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int pref[n];
        int suff[n];

        pref[0] = height[0];

        for(int i=1;i<n;i++)
        {
            pref[i] = max(height[i],pref[i-1]);
        }

        suff[n-1] = height[n-1];

        for(int i=n-2;i>=0;i--){
            suff[i] = max(height[i],suff[i+1]);
        }

        int trap = 0;
        


        for(int i=0;i<n;i++)
        {
            trap += min(pref[i],suff[i])-height[i];
        }
        
        return trap;
    }
};