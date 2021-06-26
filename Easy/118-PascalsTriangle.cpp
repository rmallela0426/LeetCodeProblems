
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 118: Pascal's Triangle
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 *
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 *
 * Constraints:
 * 1 <= numRows <= 30
*/
vector<vector<int>> generate(int numRows) {
    // 2d vector to store the result
    vector<vector<int>> res(numRows);

    // Check if the num of rows is zero
    if (numRows == 0) {
        // numRows is zero
        return res;
    }

    // Push the first row to result
    res[0].push_back({ 1 });

    // Traverse the loop
    for (int i = 1; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            // If this is first and last elements, fill it will 1
            res[i].push_back(j == 0 || j == i ? 1 : res[i - 1][j - 1] + res[i - 1][j]);
        }
    }

    return res;
}
