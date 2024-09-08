class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        long xorr = 0;  // XOR of all elements
        int b1 = 0, b2 = 0;  // To store the two unique numbers

        // Step 1: XOR all elements, the result will be XOR of the two unique numbers
        for (int i = 0; i < n; i++) {
            xorr = xorr ^ nums[i];  // XOR all elements
        }

        // Step 2: Find the rightmost set bit
        int rightMost = xorr & (xorr - 1) ^ xorr;  // Change the way rightmost bit is calculated

        // Step 3: Divide the numbers into two groups based on the rightmost set bit
        b1 = 0; 
        b2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & rightMost) {
                b1 = b1 ^ nums[i];  // XOR numbers with the rightmost set bit
            } else {
                b2 = b2 ^ nums[i];  // XOR numbers without the rightmost set bit
            }
        }

        // Step 4: Return the two unique numbers
        return {b1, b2};
    }
};
