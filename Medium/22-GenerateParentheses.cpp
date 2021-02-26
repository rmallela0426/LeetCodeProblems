/*
*  Author: Raghavendra Mallela
*/

/*
Problem Statement:
 LeetCode 22: Generate Parentheses
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

void generate(vector<string>& res, string curr, int open, int close) {
    // Here we use DFS method to solve the problem where one branch is
    // completed and procced to the next branch.

    if (open == 0 && close == 0) {
        // Generated the parenthesis, pushing to result
        res.push_back(curr);
    }

    // Generate the open parentheses
    if (open > 0) {
        generate(res, curr + '(', open - 1, close);
    }

    // Generate the close parentheses
    if (close > open) {
        generate(res, curr + ')', open, close - 1);
    }
}

void generateParentheses(int n) {
    vector<string> res;
    if (n == 0) {
        return;
    }
    string cur = "";

    generate(res, cur, n, n);

    return;
}
