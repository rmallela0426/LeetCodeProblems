
/*
 * Author: Raghavendra Mallela
*/
/*
 * LeetCode 36: Valid Sudoku
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *    . Each row must contain the digits 1-9 without repetition.
 *    . Each column must contain the digits 1-9 without repetition.
 *    . Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 *      without repetition.
 *
 * Note:
 * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 *
 * Example 1:
 * Input: board = 
 *   [["5","3",".",".","7",".",".",".","."]
 *   ,["6",".",".","1","9","5",".",".","."]
 *   ,[".","9","8",".",".",".",".","6","."]
 *   ,["8",".",".",".","6",".",".",".","3"]
 *   ,["4",".",".","8",".","3",".",".","1"]
 *   ,["7",".",".",".","2",".",".",".","6"]
 *   ,[".","6",".",".",".",".","2","8","."]
 *   ,[".",".",".","4","1","9",".",".","5"]
 *   ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 *
 * Example 2:
 * Input: board = 
 *   [["8","3",".",".","7",".",".",".","."]
 *   ,["6",".",".","1","9","5",".",".","."]
 *   ,[".","9","8",".",".",".",".","6","."]
 *   ,["8",".",".",".","6",".",".",".","3"]
 *   ,["4",".",".","8",".","3",".",".","1"]
 *   ,["7",".",".",".","2",".",".",".","6"]
 *   ,[".","6",".",".",".",".","2","8","."]
 *   ,[".",".",".","4","1","9",".",".","5"]
 *   ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner being
 * modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 *
 * Constraints:
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
*/
bool isValid(vector<vector<char>>& board, int& row, int& col, char pval) {
    // validate row to check whether pval is available or not
    for (int j = 0; j < board[row].size(); j++) {
        // check if the pval is present in the current row, col
        if (j != col && board[row][j] == pval) {
            // possible value is already present in the current row
            return false;
        }
    }

    // validate current col to check whether pval is present or not
    for (int i = 0; i < board.size(); i++) {
        // check if the pval is present in the current row, col
        if (i != row && board[i][col] == pval) {
            // possible value is already present in the current col
            return false;
        }
    }

    int smRow = 3 * (row / 3);
    int smCol = 3 * (col / 3);

    // Validate 3x3 sub boxes of the grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (smRow + i == row && smCol + j == col) {
                continue;
            }

            // check if the pval is present in current row & col
            if (board[smRow + i][smCol + j] == pval) {
                // pval is present in the subgrid
                return false;
            }
        }
    }

    // Value is not found in the currnt row, col, subgrid
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    // Traverse the board
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[row].size(); col++) {
            if (board[row][col] != '.' && !isValid(board, row, col, board[row][col])) {
                return false;
            }
        }
    }

    return true;
}
