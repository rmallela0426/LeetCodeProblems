
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

/*
 * Approach followed is a backtracking method where each parenthesis
 * combination will be generated for open and close brackets.
 *
 * Base case:
 * . when there are n open and close bracekets, a valid combination
 *   is available
*/
void dfsBacktrack(vector<string>& res, string& curr, int open, int close) {
    // Check if we have a valid combination
    if (open == 0 && close == 0) {
        // There is a valid combination of parenthisis is generated
        res.push_back(curr);
    }

    // First generate the open parenthesis first only when there are
    // open bracket request
    if (open > 0) {
        // Add an open bracket to current string
        curr += "(";
        // perform a dfs on a current combination
        dfsBacktrack(res, curr, open - 1, close);
        // backtrack as we are done with one combination
        curr.pop_back();
    }

    // Generate the close parenthesis only when there are enough close
    // requests is greater than open
    if (close > open) {
        // Add a close bracket to current string
        curr += ")";
        // perform a dfs on a current combination
        dfsBacktrack(res, curr, open, close - 1);
        // backtrack as we are done with one combination
        curr.pop_back();
    }

    return;
}

vector<string> generateParenthesis(int n) {
    // variable to store the result
    vector<string> res;

    // variable to store the current combination of brakets
    string curr;

    // Calling the dfs backtrack method to generate the parenthesis
    dfsBacktrack(res, curr, n, n);

    return res;
}
