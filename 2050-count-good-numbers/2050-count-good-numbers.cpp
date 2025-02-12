#define MOD 1000000007
class Solution {
    long long calculate(long long  x, long long  n){
       
       if( n == 0) return 1;
       

       if( n % 2 == 0){
           return calculate( (x * x) % MOD , n/2) % MOD;
       }

       return x * calculate( (x * x) % MOD, (n-1)/2) % MOD;

      
    } 
public:
    int countGoodNumbers(long long n) {
        long long even ;
        long long odd;
        if(n == 1) return 5;
        if(n % 2 == 0){
             even = n/2;
             odd = n/2;
        }else{

            even = (n+1)/2;
            odd = n/2;
        }

        long long ans1 = calculate(5,even);
        long long ans2 = calculate(4,odd);


        return (ans1*ans2) % MOD;
    }
};