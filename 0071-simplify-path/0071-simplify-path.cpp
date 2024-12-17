class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack; //using vector as a stack
        int n = path.size();
        int j = 0;

        while (j < n) {
            // Skip consecutive slashes
            while (j < n && path[j] == '/') {
                j++;
            }

            // Extract the next component
            string temp = "";
            while (j < n && path[j] != '/') {
                temp += path[j];
                j++;
            }

            // Process the component
            if (temp == "..") {
                if (!stack.empty()) {
                    stack.pop_back(); // Go back to the parent directory
                }
            } else if (!temp.empty() && temp != ".") {
                stack.push_back(temp); // Add valid directory name
            }
        }

        // Build the simplified path
        string ans = "/";
        for (int i = 0; i < stack.size(); i++) {
            ans += stack[i];
            if (i < stack.size() - 1) {
                ans += '/';
            }
        }

        return ans;
    }
};
