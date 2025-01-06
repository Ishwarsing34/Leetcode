class Solution {
public:
    char nextGreatestLetter(vector<char>& let, char target) {
        int n = let.size();

        int low = 0;
        int high = n-1;

       char ans = let[low];

        while(low<=high)
        {
            int mid = low + (high - low)/2;

            if(let[mid] > target){
                ans = let[mid];
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};