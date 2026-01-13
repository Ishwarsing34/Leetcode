class Solution {
    void recursiveCall(int i, string sumPath, long sum, long prev, string num,
                       int target, vector<string>& result) {

        if (i == num.size()) {
            if (sum == target) {
                result.push_back(sumPath);
            }
            return;
        }

        for (int j = i; j < num.size(); j++) {

            if (j > i && num[i] == '0')
                break;

            long number = stol(num.substr(i, j - i + 1));

            string tempPath = num.substr(i, j - i + 1);

            if (i == 0) {

                recursiveCall(j + 1, tempPath, number, number, num, target,
                              result);
            } else {

                recursiveCall(j + 1, sumPath + '+' + tempPath, sum + number,
                              number, num, target, result);
                recursiveCall(j + 1, sumPath + '-' + tempPath, sum - number, -number, num, target, result);
                // Multiplication operation
                recursiveCall(j + 1, sumPath + '*' + tempPath, sum - prev + (prev * number), prev * number, num,target, result);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        recursiveCall(0, "", 0, 0, num, target, result);
        // recursiveCall(CurrentIndex,Path,sum,prev,num,target,result)
        return result;
    }
};