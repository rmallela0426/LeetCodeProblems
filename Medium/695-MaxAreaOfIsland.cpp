
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 695: Max Area Of Island
 *
 * You are given an m x n binary matrix grid. An island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.)
 * You may assume all four edges of the grid are surrounded by water.
 *
 * The area of an island is the number of cells with a value 1 in the island.
 * Return the maximum area of an island in grid. If there is no island, return 0.
 *
 * Example 1:
 * Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],
 *                [0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],
 *                [0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],
 *                [0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *
 * Output: 6
 * Explanation: The answer is not 11, because the island must be connected
 * 4-directionally.
 *
 * Example 2:
 * Input: grid = [[0,0,0,0,0,0,0,0]]
 * Output: 0
 *
 * Constraints:
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] is either 0 or 1.
*/
/*
 * Approach followed is a dfs algo to find area of the island
*/
int dfsarea(vector<vector<int>>& grid, int row, int col) {
    // Check the boundary conditions ie.., grid bounds
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
        // out of bounds
        return 0;
    }

    // Check if it is an island or not
    if (grid[row][col] == 0) {
        // current element is not an island
        return 0;
    }

    // As we need to check 4 sides of an island, Change the current
    // island to water so that we can avoid this one as it is already
    // visited
    grid[row][col] = 0;

    // Evaluate the no of islands surounded the current island
    // up, down, left, right
    int area = 1 + dfsarea(grid, row - 1, col) + dfsarea(grid, row + 1, col)
        + dfsarea(grid, row, col - 1) + dfsarea(grid, row, col + 1);

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    // Variable to store the max area of the island
    int maxarea = 0;

    // Traverse the grid
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            // check if the value is an island or not
            if (grid[row][col] == 1) {
                // Its an island, procced and check the area
                maxarea = max(maxarea, dfsarea(grid, row, col));
            }
        }
    }

    return maxarea;
}
