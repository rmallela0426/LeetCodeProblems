
/*
 * Author: Raghavendra Mallela
*/

/*
 * LeetCode 970 - Powerful Integers
 *
 * Given three integers x, y, and bound, return a list of all the powerful
 * integers that have a value less than or equal to bound.
 * An integer is powerful if it can be represented as xi + yj for some integers
 * i >= 0 and j >= 0.
 *
 * You may return the answer in any order. In your answer, each value should
 * occur at most once.
 *
 * Example 1:
 * Input: x = 2, y = 3, bound = 10
 * Output: [2,3,4,5,7,9,10]
 * Explanation:
 * 2 = 20 + 30
 * 3 = 21 + 30
 * 4 = 20 + 31
 * 5 = 21 + 31
 * 7 = 22 + 31
 * 9 = 23 + 30
 * 10 = 20 + 32
 *
 * Example 2:
 * Input: x = 3, y = 5, bound = 15
 * Output: [2,4,6,8,10,14]
 *
 * Constraints:
 * 1 <= x, y <= 100
 * 0 <= bound <= 106
*/
/*
 * Approach followed is a brute force method. we can see that the
 * power of x goes from 0... y and power of y goes from 0...x,
 * performing a double loop and calculating the power interger and
 * checcking for bound
*/
vector<int> powerfulIntegers(int x, int y, int bound) {
    // Set to remove Duplicates
    unordered_set<int> st;

    // First loop starts with 1 ie.., x^0
    for (int i = 1; i < bound; i *= x) {
        // Inner loop starts with 1 ie.., y^0 and runs till powerful
        // integer reaches the bound
        for (int j = 1; i + j <= bound; j *= y) {
            // As i & j are already powers, push it to set
            st.insert(i + j);

            // Cornor case where if y == 1, the loops continues forever
            if (y == 1) {
                // Break if y == 1, to avoid forever loop
                break;
            }
        }
        // Cornor case where if x == 1, the loop continues forever
        if (x == 1) {
            break;
        }
    }

    return vector<int>(st.begin(), st.end());
}
