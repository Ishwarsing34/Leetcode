class Solution {
public:
    string sortSentence(string s) {
        int n = s.size();
        int i = 0;
        vector<string> words(9, ""); // Initialize vector to store words by position

        while (i < n) {
            string temp = "";

            // Collect the word
            while (i < n && isalpha(s[i])) { // Fixed: Added condition i < n
                temp.push_back(s[i]);
                i++;
            }

            // Collect the position number of the word
            if (i < n && isdigit(s[i])) { // Process the digit for position
                int pos = s[i] - '1';  // Convert digit to zero-based index
                words[pos] = temp;     // Store word in the correct position
                i++; // Move past the digit
            }

            // Skip any spaces after the digit
            while (i < n && s[i] == ' ') {
                i++;
            }
        }

        // Form the final sentence
        string ans = "";
        for (const string& word : words) { // Iterate over words vector
            if (!word.empty()) { // Check if word is not empty
                if (!ans.empty()) {
                    ans += " "; // Add space between words
                }
                ans += word; // Append word to final answer
            }
        }

        return ans;
    }
};
