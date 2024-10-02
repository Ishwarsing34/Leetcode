class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr; // Create a copy of the original array
        sort(sortedArr.begin(), sortedArr.end()); // Sort the array
        
        // Map to store the rank of each unique element
        unordered_map<int, int> rankMap;
        int rank = 1; // Start ranking from 1

        // Assign ranks to unique elements
        for (int num : sortedArr) {
            // Only assign a rank if it's the first occurrence of the number
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }

        // Build the result array using the rank map
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }

        return result;
    }
};
