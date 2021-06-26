
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 437: Matchsticks To Square
 *
 * You are given an integer array matchsticks where matchsticks[i] is the length of the
 * ith matchstick. You want to use all the matchsticks to make one square. You shouldn't
 * break any stick, but you can link them up, and each matchstick must be used exactly
 * one time.
 *
 * Return true if you can make this square and false otherwise.
 *
 * Example 1:
 * Input: matchsticks = [1,1,2,2,2]
 * Output: true
 * Explanation: You can form a square with length 2, one side of the square came two sticks
 *              with length 1.
 *
 * Example 2:
 * Input: matchsticks = [3,3,3,3,4]
 * Output: false
 * Explanation: You cannot find a way to form a square with all the matchsticks.
 *
 * Constraints:
 * 1 <= matchsticks.length <= 15
 * 0 <= matchsticks[i] <= 109
*/
/*
 * Approach followed is a dfs backtracking algorithm
 *
 * The sides in a square are equal and perimeter = 4 * a where a
 * is length of the side. So the sum of lengths of matchsticks
 * should be divisible by 4 and length of each side is
 *                 p = 4 * a => a = p / 4
 *
 * Now each side should have p / 4 length of match sticks.
 *
 * . As discussed, we will use dfs backtracking solution where the
 *   function takes the current index of matchstick that we are
 *   currently processing and four sides of a square that needs
 *   to be formed
 * . If all the matchsticks are used up and all sides are zero
 *   length ie.., the square is formed.
 * . If not perform a dfs on all four sides of the square. If that
 *   dfs true, will return true
 *
*/
bool dfsBacktrack(vector<int>& ms, int idx/*Current matchstick index*/, vector<int>& sides) {
    // Base case when we are done with all matchsticks
    if (idx >= ms.size()) {
        // check whether all sides are formed or not, if formed
        // return true
        return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0;
    }

    // Apply current matchstick to all sides of a square
    for (int& side : sides) {
        // Check if matchstick length is fit or not for current side
        if (ms[idx] <= side) {
            // The current matchstick can be kept on the current side
            // Reduce the matchstick length
            side -= ms[idx];
            // dfs for the next matchstick idx
            if (dfsBacktrack(ms, idx + 1, sides)) {
                return true;
            }
            // backtrack
            side += ms[idx];
        }
    }

    return false;
}

bool makesquare(vector<int>& matchsticks) {
    // Check if there are enough matchsticks to form a square
    if (matchsticks.size() < 4) {
        // No enough matchsticks, can't able to form a square
        return false;
    }

    // calculate the sum of length of the matchsticks, if this
    // is a multiple of 4 then we can form a square
    int p = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    // Check if the perimeter is zero or multiple of 4
    if (p % 4 != 0) {
        // perimeter is not a multiple of 4, we can't form a square
        return false;
    }

    // Initialize 4 sides of a square with a length of perimeter / 4
    vector<int> sides(4, p / 4);

    // Sort the array in decreasing order so that the traversing will be
    // faster
    sort(matchsticks.rbegin(), matchsticks.rend());

    // DFS backtracking
    return dfsBacktrack(matchsticks, 0, sides);
}
