class Solution {
public:
    int hIndex(vector<int>& cit) {

        int n = cit.size();
        int low = 0;
        int high = n-1;

        while(low<=high){

            int mid = low + (high-low)/2;

            if(n-mid == cit[mid]) return n-mid;
            else if(n-mid < cit[mid]) high = mid - 1;
            else low = mid + 1;
        }

        return  n - low;


    }
};