
/*
 * Author: Raghavendra Mallela
*/
/*
 * LeetCode 37: Sudoku Solver
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * A sudoku solution must satisfy all of the following rules:
 *  . Each of the digits 1-9 must occur exactly once in each row.
 *  . Each of the digits 1-9 must occur exactly once in each column.
 *  . Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 *    sub-boxes of the grid.
 * The '.' character indicates empty cells.
 *
 * Example 1:
 *       "5"  "3"  "."  "."  "7"  "."  "."  "."  "."
 *       "6"  "."  "."  "1"  "9"  "5"  "."  "."  "."
 *       "."  "9"  "8"  "."  "."  "."  "."  "6"  "."
 *       "8"  "."  "."  "."  "6"  "."  "."  "."  "3"
 *       "4"  "."  "."  "8"  "."  "3"  "."  "."  "1"
 *       "7"  "."  "."  "."  "2"  "."  "."  "."  "6"
 *       "."  "6"  "."  "."  "."  "."  "2"  "8"  "."
 *       "."  "."  "."  "4"  "1"  "9"  "."  "."  "5"
 *       "."  "."  "."  "."  "8"  "."  "."  "7"  "9"
 * 
 * Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],
 *                 [".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],
 *                 ["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],
 *                 [".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],
 *                 [".",".",".",".","8",".",".","7","9"]]
 *
 * Output: board =  [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],
 *                   ["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],
 *                   ["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],
 *                   ["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],
 *                   ["3","4","5","2","8","6","1","7","9"]]
 *
 * Constraints:
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
*/
/*
 * Approach followed is a back tracking method where algo travers
 * each row and col and check the possible values from 1 to 9 whether
 * the value is valid or not if not a valid value backtrack to the
 * previous columns and find another possible value
 *
 * For every backtracking problem, we have 3 things to be noted
 * Our Choice, Constraints and Goal
 * Our Choice - need to place 1 to 9 numbers in each col, row
 * Our Constraints - the possible value should be valid ie..., it should
 *             not be in the row, col and subgrid.
 * Our Goal - to fill the board with proper values
*/
bool isValid(vector<vector<char>>& board, int& row, int& col, char pval) {
    // validate row to check whether pval is available or not
    for (int j = 0; j < board[row].size(); j++) {
        // check if the pval is present in the current row, col
        if (board[row][j] == pval) {
            // possible value is already present in the current row
            return false;
        }
    }

    // validate current col to check whether pval is present or not
    for (int i = 0; i < board.size(); i++) {
        // check if the pval is present in the current row, col
        if (board[i][col] == pval) {
            // possible value is already present in the current col
            return false;
        }
    }

    int smRow = 3 * (row / 3);
    int smCol = 3 * (col / 3);

    // Validate 3x3 sub boxes of the grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
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

bool solveSudoku(vector<vector<char>>& board, int row, int col) {
    // Check whether we are done with all rows
    if (row == board.size()) {
        // Done with all the rows
        return true;
    }

    // variables that store the next row and col values
    int nextRow = row;
    int nextCol = col + 1;

    // Check if we reach the last column
    if (col == board[row].size() - 1) {
        // At the last column, only traversal is to next row
        nextRow = row + 1;
        nextCol = 0;
    }

    // Check if it is not an empty cell
    if (board[row][col] != '.') {
        // char at this row & col (cell) is not an empty
        // procced with the nextRow and nextCol
        return solveSudoku(board, nextRow, nextCol);
    }

    // traversal all the values from 1 to 9
    for (int pval = 1; pval <= 9; pval++) {
        // Check if the current possible value is valid or not
        if (isValid(board, row, col, pval + '0')) {
            // valid possible value, place it at curr position in board
            board[row][col] = pval + '0';
            // procced with the next row and col
            if (solveSudoku(board, nextRow, nextCol)) {
                // board is done, returning true
                return true;
            }
            // Backtrack place '.' at the current row and col
            board[row][col] = '.';
        }
    }

    // Not solved the board
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudoku(board, 0, 0);

    return;
}
