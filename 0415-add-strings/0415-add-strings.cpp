class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int carry = 0;
        string ans = "";

        int i = n - 1; // Pointer for num1
        int j = m - 1; // Pointer for num2

        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? num1[i] - '0' : 0; // Get digit from num1 or 0 if out of bounds
            int digit2 = (j >= 0) ? num2[j] - '0' : 0; // Get digit from num2 or 0 if out of bounds

            int sum = digit1 + digit2 + carry; // Calculate sum with carry
            carry = sum / 10; // Update carry
            sum = sum % 10;   // Get the last digit of the sum

            ans += to_string(sum); // Append current digit to result

            i--; // Move to the next digit in num1
            j--; // Move to the next digit in num2
        }

        reverse(ans.begin(), ans.end()); // Reverse result to get the final answer

        return ans;
    }
};
