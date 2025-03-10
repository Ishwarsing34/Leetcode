class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1,mp2;



        for(auto it:nums1){
            mp1[it]++;
        }

        for(auto it:nums2){
            mp2[it]++;
        }
        
        int cnt1  = 0;
        int cnt2 = 0;

        vector<int>ans;

        for(int i=0;i<nums1.size();i++){

            int a = nums1[i];

            if(mp2.find(a) != mp2.end()){
                cnt1++;
            }
        }


        for(int i=0;i<nums2.size();i++){
            int a = nums2[i];

            if(mp1.find(a) != mp1.end()){
                cnt2++;
            }
        }

        ans.push_back(cnt1);
        ans.push_back(cnt2);

        return ans;

    }
};