class Solution {
public:
    bool isPalindrome(int x) {
        long long rev_num=0;
        int original=x;
        while(x>0)
        {
           int last=x%10;
            rev_num=(rev_num*10)+last;
            x/=10;
        }

        return (original==rev_num);
    }
};