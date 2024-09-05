class Solution {
public:
    int reverse(int x) {
       long rev_num=0;

        while(x)
        { 
           
           long last_dig=x%10;
            rev_num=(rev_num*10)+last_dig;
            x/=10;
            if(rev_num>INT_MAX || rev_num<INT_MIN) return 0;
        }

         
        return long(rev_num);
        
        
        
        
    }
};