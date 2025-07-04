class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = cit.size();

        int low = 0 , high = n - 1;

        while(low<=high)
        {
            int mid  = low + (high-low)/2;

            if(cit[mid] == n-mid) return n-mid;
            else if(cit[mid] > n-mid) high = mid - 1;
            else low = mid + 1;
        }

        return n-low;
    }
};