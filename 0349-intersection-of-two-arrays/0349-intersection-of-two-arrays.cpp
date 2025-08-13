class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        map<int, int> mp1;
        map<int, int> mp2;

        for (int i = 0; i < nums1.size(); i++) {
            mp1[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++) {
            mp2[nums2[i]]++;
        }

        for (auto v1 : mp1) {
            for (auto v2 : mp2) {
                if (v1.first == v2.first) {
                    ans.push_back(v1.first);
                }
            }
        }

        return ans;
    }
};