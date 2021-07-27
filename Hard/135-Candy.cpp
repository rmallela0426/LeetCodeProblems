
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 135: Candy
 *
 * There are n children standing in a line. Each child is assigned a rating value given
 * in the integer array ratings.
 *
 * You are giving candies to these children subjected to the following requirements:
 *   . Each child must have at least one candy.
 *   . Children with a higher rating get more candies than their neighbors.
 *
 * Return the minimum number of candies you need to have to distribute the candies to the
 * children.
 *
 * Example 1:
 * Input: ratings = [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies
 *              respectively.
 *
 * Example 2:
 * Input: ratings = [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies
 *              respectively.
 * The third child gets 1 candy because it satisfies the above two conditions.
 *
 * Constraints:
 * n == ratings.length
 * 1 <= n <= 2 * 104
 * 0 <= ratings[i] <= 2 * 104
*/
/*
 * Approach followed is a greedy solution, where the initial
 * candy distribution is 1 for all children. Now let scan from
 * left to right and see if the current child rating is greater
 * than the previous child, if so then increase the no of candy
 * for the current child
 * Eg: rating = [1, 2]
 *     candy = [1, 1]
 * As 2nd child rating is greater than 1st child, the candies
 * should be atleast 1 greater than previous child.
 * => candy[i] = candy[i - 1] + 1 only when rating[i] > rating[i - 1]
 *
 * Now we need to scan from right to left to see whether candies
 * for higher rating should get more than its neighbours
 *  Eg: rating =  [2, 1]
 *       candy = [1, 1]
 * When we scan from right to left, the rating of 1st child is
 * greater than 2nd child, so 1st child should get more candies
 * only when 1st child has less than or equal candies of 2nd child
 * and when rating of 1st child is greater than 2nd child.
 * => candy[i] = candy[i + 1] + 1 only when candy[i] <= candy[i + 1]
 *                 and rating[i] > rating[i + 1]
*/
int candy(vector<int>& ratings) {
    // Base case: If there are no children
    if (ratings.empty()) {
        // There are no children
        return 0;
    }

    int n = ratings.size();
    // Vector to store the min number of candies for each children
    // Each child should get atleast one candy, so initialising the
    // array with 1
    vector<int> candy(n, 1);
    // storing the min number of candies, which is no of child
    int minCandies = n;

    // Scan the ratings from left to right
    for (int i = 1; i < n; i++) {
        // check if the rating of the current child is greater than
        // previous child
        if (ratings[i] > ratings[i - 1]) {
            // Remove the candy that are at present with current child
            minCandies -= candy[i];
            // Current child has higher rating, child should get more
            // candies
            candy[i] = candy[i - 1] + 1;
            // Increase the total no of candies
            minCandies += candy[i];
        }
    }

    // Scan the ratings from right to left
    for (int i = n - 2; i >= 0; --i) {
        // Check if the rating of the current child is greater than that
        // of the neighbour child. If so, check if current child has less
        // candies than tha of neighbour child
        if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
            // Remove the candy that are at present with current child
            minCandies -= candy[i];
            // Current child has higher rating and should have more candies
            // than that of its neighbour child
            candy[i] = candy[i + 1] + 1;
            // Update the total no of candies
            minCandies += candy[i];
        }
    }

    // Return total no of candies required to distribute to children
    return minCandies;
}
