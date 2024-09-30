class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int cntZ=0;
        int cntO=0;
        int result=0;
        int temp=0;
        for(int k=0;k<=31;k++)
        {
            cntZ=cntO=0;
            temp=(1<<k);

            for(int &num : nums){
                if((num & temp)==0) cntZ++;
                else cntO++;
                
            }

            if(cntO % 3 == 1)
            {
                result |= temp;
            }
        }
        return result;
    }
};