https://leetcode.com/problems/expression-add-operators/submissions/1692116739/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string path;
        backtrack(num, target, 0, 0, 0, path, result);
        return result;
    }

    void backtrack(const string& num, int target, int index, long currValue, long prevNum,
                   string path, vector<string>& result) {
        // Base case: if we reached the end of the string
        if (index == num.length()) {
            if (currValue == target) {
                result.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.length(); i++) {
            // Skip numbers with leading zeros
            if (i > index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long number = stol(part);// convert string into long int

            if (index == 0) {
                // First number: just take it, no operator
                backtrack(num, target, i + 1, number, number, part, result);
            } else {
                // '+' operator
                backtrack(num, target, i + 1, currValue + number, number, path + "+" + part, result);

                // '-' operator
                backtrack(num, target, i + 1, currValue - number, -number, path + "-" + part, result);

                // '*' operator
                backtrack(num, target, i + 1,
                          currValue - prevNum + prevNum * number, prevNum * number,
                          path + "*" + part, result);
            }
        }
    }
};
