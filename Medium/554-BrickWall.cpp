
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 554: Brick Wall
 *
 * There is a brick wall in front of you. The wall is rectangular and has several rows of bricks.
 * The bricks have the same height but different width. You want to draw a vertical line from the
 * top to the bottom and cross the least bricks.
 * The brick wall is represented by a list of rows. Each row is a list of integers representing
 * the width of each brick in this row from left to right.
 * If your line go through the edge of a brick, then the brick is not considered as crossed. You
 * need to find out how to draw the line to cross the least bricks and return the number of crossed
 * bricks.
 * You cannot draw a line just along one of the two vertical edges of the wall, in which case the
 * line will obviously cross no bricks.
 *
 * Example:
 * Input: [[1,2,2,1],
 *         [3,1,2],
 *         [1,3,2],
 *         [2,4],
 *         [3,1,2],
 *         [1,3,1,1]]
 * Output: 2
 *
 * Note:
 * The width sum of bricks in different rows are the same and won't exceed INT_MAX.
 * The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000].
 * Total number of bricks of the wall won't exceed 20,000.
*/
/*
 * As we need to find the least no of bricks that are
 * crossed when a vertical line is drawn from top to
 * bottom i.e.., the line should be drawn with a maximum
 * no of gaps.
 *   num of gaps + num of crosses == num of rows
 * => num of crosses = num of rows - num of gaps
 *
 * From above it is seen that if the line goes with maximum
 * of gaps between the bricks then line crosses the least
 * no of bricks.
 * Eg: [[1,2], [2, 1], [1,1, 1]]
 * First find the num of gaps where the line passes
 * for each row
 * For Row 1: w: 1 -> 1 gap
 * For Row 2: w: 2 -> 1 gap
 * For Row 3: w: 1 -> 1 gap, w: 2 -> 1 gap
 *
 * The total no of gaps at each width is
 *     w: 1 -> 2 gaps
 *     w: 2 -> 2 gaps
 * If vertical line is drawn at either each brick width of
 * 1 or 2, there will be min no of crosses.
*/
int leastBricks(vector<vector<int>>& wall) {
    // Map to store the num of gaps at each brick width
    unordered_map<int/*width*/, int/*numGaps*/> gaps;

    // Loop for all bricks and find where the total num of
    // gaps at each width for each row and find the maximum
    // gaps between the bricks
    int maxGaps = 0;
    for (int row = 0; row < wall.size(); row++) {
        // variable to store the sum of widths
        int sum = 0;
        // As the line cannot be drawn along the vertical edges,
        // ignoring the last width
        for (int col = 0; col < wall[row].size() - 1; col++) {
            sum += wall[row][col];
            gaps[sum] += 1;
            maxGaps = max(maxGaps, gaps[sum]);
        }
    }

    // Now that we have the num of gaps at widths of the bricks
    // find the least num of crosses
    return wall.size() - maxGaps;
}
