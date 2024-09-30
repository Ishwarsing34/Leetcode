class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int cntOnes = 0, cntZeros = 0;
        int temp = 0;
        int result = 0;

        for (int k = 0; k <= 31; k++) {
            temp = (1 << k);
            
            cntOnes = cntZeros = 0;

            for (int &num : nums) {
                if ((num & temp) == 0) cntZeros++;
                else cntOnes++;
            }

            if (cntOnes % 3 == 1) {
                result |= temp;
            }
        }

        return result;
    }
};
