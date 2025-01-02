class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq{0};

        for(int i=1;i<n;i++)
        {
            while(dq.front() < i - k)
            {
                dq.pop_front();
            }
            nums[i] += nums[dq.front()];

            while(!dq.empty() and nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return nums.back();
    }
};