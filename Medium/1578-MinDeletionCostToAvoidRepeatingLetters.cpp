
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1578: Minimum Deletion Cost Of Repating Letters
 *
 * Given a string s and an array of integers cost where cost[i] is the cost of deleting the
 * ith character in s.
 * Return the minimum cost of deletions such that there are no two identical letters next to
 * each other.
 * Notice that you will delete the chosen characters at the same time, in other words, after
 * deleting a character, the costs of deleting other characters will not change.
 *
 * Example 1:
 * Input: s = "abaac", cost = [1,2,3,4,5]
 * Output: 3
 * Explanation: Delete the letter "a" with cost 3 to get "abac" (String without two identical
 * letters next to each other).
 *
 * Example 2:
 * Input: s = "abc", cost = [1,2,3]
 * Output: 0
 * Explanation: You don't need to delete any character because there are no identical letters
 * next to each other.
 *
 * Example 3:
 * Input: s = "aabaa", cost = [1,2,3,4,1]
 * Output: 2
 * Explanation: Delete the first and the last character, getting the string ("aba").
 *
 * Constraints:
 * s.length == cost.length
 * 1 <= s.length, cost.length <= 10^5
 * 1 <= cost[i] <= 10^4
 * s contains only lowercase English letters.
*/
/*
 * Approach followed is a greedy solution where the letters to be
 * deleted are consecutive, traverse the loop and maintain group
 * sum and the max cost for each group of repeating letters. Once
 * there starts a different group, update the min sum for deleting
 * the characters
 * Eg: s= "aaabbb"  cost = [3,5,10,7,8, 14]
 * we can see that there are 3 consecutive a's, we need to delete
 * min cost ones ie..., 3,5
*/
int minCost(string s, vector<int>& cost) {
    // BaseCase: If the input string is empty
    if (s.empty()) {
        // Input string is empty, nothing to delete
        return 0;
    }

    // variable to store the sum of a group initialize to 0th cost
    // running sum
    int gsum = cost[0];
    // variable to store the max cost of the group which helps to
    // remove from group sum so that will get the min cost
    // Initializing with 0th char cost removal
    int gmax = cost[0];
    // variable to store the min cost
    int mincost = 0;

    // Traverse all the characters from 1 to n
    for (int i = 1; i < s.length(); i++) {
        // Check if current char is not same a previous ie.. whether
        // the group is ended here or not
        if (s[i - 1] != s[i]) {
            // Current char is not same as previous the group is ended
            // Update the result where the gsum is calculated and the
            // max cost is also calculated
            // Get the sum of min cost of chars that need to be removed
            // from the previous group
            mincost += gsum - gmax;
            // Reset the group sum and group max so that it will be sued
            // for next group
            gsum = 0;
            gmax = 0;
        }

        // Calculate the running sum
        gsum += cost[i];
        // Calculate the group max
        gmax = max(gmax, cost[i]);
    }

    // Cornor case where if the input string has same char then above loop
    // won't calculate the min sum
    // Eg: "bbbb"
    mincost += gsum - gmax;

    return mincost;
}
