#define MOD 1000000007

class Solution {
    long long calculate(long long x, long long n) {
        if (n == 0) return 1; // Base case

        long long half = calculate((x * x) % MOD, n / 2) % MOD; // Avoid overflow with MOD

        if (n % 2 == 0) return half; // If even power
        return (x * half) % MOD; // If odd power, multiply one more time
    }

public:
    int countGoodNumbers(long long n) {
        if (n == 1) return 5;  // Special case: Only one digit, and it must be an even digit

        long long even = (n + 1) / 2;  // Ceiling of n/2
        long long odd = n / 2;         // Floor of n/2

        long long ans1 = calculate(5, even); // `even` places hold prime digits (5 options)
        long long ans2 = calculate(4, odd); // `odd` places hold even digits (4 options)

        return (ans1 * ans2) % MOD; // Final result under modulo
    }
};
