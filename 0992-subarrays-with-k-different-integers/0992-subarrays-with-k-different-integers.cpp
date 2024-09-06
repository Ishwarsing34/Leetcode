class Solution {
private:
    int  atMostk(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int right = 0;
        int left = 0;
        int cnt=0;
        int n = nums.size();

        while(right<n) {

            freq[nums[right]]++;

            while(freq.size()>k){

                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }

            cnt += (right-left+1);
            right++;
        }

        return cnt;

    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostk(nums,k) - atMostk(nums,k-1);
    }
};