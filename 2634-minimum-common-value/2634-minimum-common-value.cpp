//Approach-2 (Using Binary Search)
//T.C : O(mlogn)
//S.C : O(1)
class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return false;
    }
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        for(int &num : nums2) {
            if(binarySearch(nums1, num))
                return num;
        }
        
        return -1;
    }
};

