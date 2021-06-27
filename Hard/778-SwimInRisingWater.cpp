
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 778: Swim In Rising Water
 *
 * On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).
 * Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a
 * square to another 4-directionally adjacent square if and only if the elevation of both squares
 * individually are at most t. You can swim infinite distance in zero time. Of course, you must stay
 * within the boundaries of the grid during your swim.
 *
 * You start at the top left square (0, 0). What is the least time until you can reach the bottom
 * right square (N-1, N-1)?
 *
 * Example 1:
 * Input: [[0,2],[1,3]]
 * Output: 3
 * Explanation:
 * At time 0, you are in grid location (0, 0).
 * You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation
 * than t = 0.
 * You cannot reach point (1, 1) until time 3.
 * When the depth of water is 3, we can swim anywhere inside the grid.
 *
 * Example 2:
 * Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 * Output: 16
 * Explanation:
 *   0  1  2  3  4
 *  24 23 22 21  5
 *  12 13 14 15 16
 *  11 17 18 19 20
 *  10  9  8  7  6
 * The final route is marked in bold.
 * We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 *
 * Note:
 * 2 <= N <= 50.
 * grid[i][j] is a permutation of [0, ..., N*N - 1].
*/
/*
 * Approach followed is BFS solution, where each tile is pushed onto
 * queue. Loop traverses until queue is empty.
 * For every tile, we move in 4 directions left, right, top, down which
 * checks for each direction whether this is valid and calcualte the
 * max elapsed time and save it in an elapsed time array for that current
 * tile.
 *
*/

int swimInWater(vector<vector<int>>& grid) {
    // Base case
    if (grid.empty()) {
        // Grid is empty return 0
        return 0;
    }

    // Dp array to store the min elapsed time to swim to that tile
    vector<vector<int>> dp(grid.size(), vector<int>(grid.size(), INT_MAX));

    // Queue to store the current level nodes
    std::queue<pair<int, int>> q;

    // Push the starting node ie.., start tile to queue
    q.push({ 0, 0 });

    // Push the elapsed time to reach the tile (0, 0) from (0,0)
    // ie.., elapsed time of tile (0,0)
    dp[0][0] = grid[0][0];

    // Lambda function to check the boundary conditions
    auto isvalid = [&](int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid.size();
    };

    // Lambda function to update the values
    // variables to store the current tile coordinates
    int x;
    int y;

    // Temp Variables to store the coordinates of next tile x, y
    int next_x;
    int next_y;
    int nElapsedTime;

    // Directions
    vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    // Traverse the loop while queue is empty
    while (!q.empty()) {
        // Retrieve the top tile form teh queue
        x = q.front().first;
        y = q.front().second;

        // Remove Current tile from Queue
        q.pop();

        // Move in all 4 directions and try to check whether this is valid
        // or not and find the min path to next grid
        for (pair<int, int>& dir : dirs) {
            // Get the next tile coordinates
            next_x = x + dir.first;
            next_y = y + dir.second;

            // Check if this tile is valid
            if (isvalid(next_x, next_y)) {
                // Calculated the max elapsed time
                nElapsedTime = max(dp[x][y], grid[next_x][next_y]);

                // Check if this is min elapsed time from all paths in the tile
                if (nElapsedTime < dp[next_x][next_y]) {
                    // This would be min path to reach this tile, update it
                    dp[next_x][next_y] = nElapsedTime;
                    q.push({ next_x, next_y });
                }
            }
        }
    }

    return dp[grid.size() - 1][grid.size() - 1];
}
