
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 79: Word Search
 *
 * Given an m x n grid of characters board and a string word, return true if word exists
 * in the grid.
 * The word can be constructed from letters of sequentially adjacent cells, where adjacent
 * cells are horizontally or vertically neighboring. The same letter cell may not be used
 * more than once.
 *
 * Example 1:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 * Output: true
 *
 * Example 2:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 * Output: true
 *
 * Example 3:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
 * Output: false
 *
 * Constraints:
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

/*
 * Approach followed is DFS + Backtracking, where we traverse
 * the board from 0 and check if char is same as the word first
 * char, dfs and try to find all other chars
*/
bool dfs(vector<vector<char>>& board, string& word, int row, int col, int wordPos) {
    // check if we are done with all chars in the search word
    if (wordPos == word.length()) {
        // done with all chars in the search wod
        return true;
    }

    // Check the boundary conditions where the row and col goes beyond range
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
        // we are out of array bounds, return false
        return false;
    }

    // Check if the char at the current row and col is same as Search Word char
    if (word[wordPos] != board[row][col]) {
        // Not the same char, return
        return false;
    }

    // Char matches the searchword char, need to replace it with '*' as same letter
    // cell may not be used more than once
    char temp = board[row][col];
    board[row][col] = '*';

    // We have a char that can be found in the board, search for other chars
    // in all four directions i.e.., up, down, left, right
    if (dfs(board, word, row - 1, col, wordPos + 1) ||
        dfs(board, word, row + 1, col, wordPos + 1) ||
        dfs(board, word, row, col - 1, wordPos + 1) ||
        dfs(board, word, row, col + 1, wordPos + 1)) {
        // Found word in the board
        return true;
    }

    // backtrack, place the original char
    board[row][col] = temp;

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    // Traverse the board
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            // check if the current char in the board is same char
            // at search word
            if (word[0] == board[row][col] && dfs(board, word, row, col, 0/*wordPos*/)) {
                // word exist in the board
                return true;
            }
        }
    }

    // Word doesn't exist in board
    return false;
}
