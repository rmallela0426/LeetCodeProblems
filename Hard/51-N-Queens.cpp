
/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 51: N-Queens
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 *
 * Example 1:
 *     x   Q1   x   x               x    x    Q1   x
 *     x   x    x   Q2              Q2   x    x    x
 *     Q3  x    x   x               x    x    x    Q3
 *     x   x    Q3  x               x    Q2   x    x
 * 
 *  where x is empty, Q' are the queens
 *
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 *
 * Example 2:
 * Input: n = 1
 * Output: [["Q"]]
 *
 * Constraints:
 * 1 <= n <= 9
*/
/*
 * For N-Queens problem all distinct solutions need to be found, so
 * we use a backtracking algorithm, if an optimal solution is needed
 * then dynamic programming can be used.
 * In chess, the queen can move vertical, horizantal and diagnol and
 * constraint mentioned is that no two queens attack each other ie..,
 *               Q1  x    x  x
 *               x   x
 *               x        x
 *               x           x
 * From above we can see that Q2 can be placed on row1 & col3 and so on.
 *
*/
bool isValid(vector<int>& pos) {
    // We need to check queen position of current row with all queen
    // positions of previous rows. So loop goes till the previous row
    // Loop goes till the previous row
    int row = pos.size() - 1;

    // Try to find whether the queens are in attacking or not
    for (int i = 0; i < row; i++) {
        // Check the difference of the queen pos on i th row with that of
        // current row
        int diff = abs(pos[i] - pos[row]);

        // Check if it is in same column or same row or same diagnol
        // If it is same col or row, then diff will be zero, if diff
        // is equal to row - i then it is in same col
        if (diff == 0 || diff == row - i) {
            return false;
        }
    }

    // Queen is in right position
    return true;
}

void solveNqueens(int n, int row, vector<int>& queenPos, vector<vector<string>>& res) {
    // Boundary Case where all rows are completed
    if (n == row) {
        // Done with all the rows and queens, generate the result
        vector<string> temp;
        for (int& pos : queenPos) {
            // Generate the string based on the current queen pos
            string str(n, '.');
            str[pos] = 'Q';
            temp.push_back(str);
        }
        // Push the current solution to result
        res.push_back(temp);

        return;
    }

    // As all distinct solutions need to find, loop for all columns
    for (int col = 0; col < n; col++) {
        // Place the queen in the col for current row
        queenPos.push_back(col);

        // Check if it is a valid placement ie.., whether the queens are
        // in attack or not
        if (isValid(queenPos)) {
            // The current queen pos is valid, proceed with next row
            solveNqueens(n, row + 1, queenPos, res);
        }

        // Done with the current col, remove form array queenPos to place it
        // for a new position
        //queenPos.erase(queenPos.begin() + row);
        queenPos.pop_back();
    }

    return;
}

vector<vector<string>> solveNQueens(int n) {
    // Stroring the result as the chess board is nxn, a double dimensional
    // array
    vector<vector<string>> res;

    if (n == 1) {
        // Only one queen and one row and one col
        res.push_back({ "Q" });
    }
    else {
        // array holds the queens position at each row
        vector<int> queensPos;

        // Helper method to solve N-Queens problem using backtracking
        solveNqueens(n, 0/*current row*/, queensPos, res);
    }

    return res;
}
