
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 200: Number Of Islands
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land)
 * and '0's (water), return the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 * Example 1:
 * Input: grid = [
 * ["1","1","1","1","0"],
 * ["1","1","0","1","0"],
 * ["1","1","0","0","0"],
 * ["0","0","0","0","0"]]
 * Output: 1
 *
 * Example 2:
 * Input: grid = [
 * ["1","1","0","0","0"],
 * ["1","1","0","0","0"],
 * ["0","0","1","0","0"],
 * ["0","0","0","1","1"]]
 * Output: 3
 * 
 * Constraints:
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
*/
/*
 * Solution is to find num of islands that are surrounded by water
 * and is formed by connecting adjacent lands horizontally/vertically
 *      -------------
 * Eg   | 1  1  1  1 | 0
 *                 --
 *      | 1  1  1| 0   0
 *           -----
 *      | 1 | 0  0  0  0
 *       ---
 * In this example, we can see that there is only one island as the land
 * is surrounded by water and are connected horizontally or vertically.
 * Best approach to solve this problem is using DFS where we traverse the
 * grid and if there is an island, increment the count and perform dfs to
 * search all other islands surrounded it. As at any particular position
 * in grid, we can search for land in all four direction left, right, up
 * and down. So if we found a land, we replace it with 0 or 2 to make sure
 * that the land is already visited.
 *
 * BaseCases:
 *   . Row and Column indices reaches grid bounds
 *   . If there is no land in the current grid position
*/

void dfs(vector<vector<char>>& grid, int row, int col) {
    // Check if the row and col indices are out of grid bounds
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
        // row and col indices are out of bounds
        return;
    }

    // Check if it is land or not at current position
    if (grid[row][col] != '1') {
        // current position is not a land
        return;
    }

    // Current position has a land and need to search for all lands surrounding
    // it. As the land is searched in all four directions, changing the value at
    // current position in grip to mark it as visited
    grid[row][col] = '2';

    // Search in all four directions up, down, left, right
    // Up
    dfs(grid, row - 1, col);
    // down
    dfs(grid, row + 1, col);
    // left
    dfs(grid, row, col - 1);
    // right
    dfs(grid, row, col + 1);

    return;
}

int numIslands(vector<vector<char>>& grid) {
    // Variable to store num of islands
    int numIslands = 0;

    // Traverse the grid
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            // check if the value is an island or not
            if (grid[row][col] == '1') {
                // This is an island, increment the count
                numIslands++;

                // Exclude the islands surrounded to it
                dfs(grid, row, col);
            }
        }
    }

    return numIslands;
}
