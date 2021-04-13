
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 322: Coin Change
 * You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that
 * amount. If that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 * Example 1:
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 * Example 3:
 * Input: coins = [1], amount = 0
 * Output: 0
 *
 * Example 4:
 * Input: coins = [1], amount = 1
 * Output: 1
 *
 * Constraints:
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 231 - 1
 * 0 <= amount <= 104
*/
/*
 * TopDown Approach or Recursive Solution
 *
 * There will be n subproblems for each problem i.e.., for each remainder amount, each coin in the
 * will be substracted and it goes on until the remainder is 0 or remainder is < 0
 * Eg: [1, 2, 5] amount = 11
 *                               11
 *                               |
 *                       -------------------
 *                      |        |         |
 *                    10(11-1)  9(11-2)   6(11-5)
 *                     |
 *             -----------------
 *             |      |        |
 *           9(10-1) 8(10-2) 5(10-5)
 *
 * From above it is clear that for each iteration, there will n loop where n is no of denominations
 *
 *    for (int coin: conins) {
 *       int coinchange = coinchange(coins, amount-coin);
 *    }
 *
 * As there are many duplicate subproblems from above, the approach used is memonization
 * Base cases:
 * If the remainder amt is 0, then we have solution for that problem, return 1
 * If the remainder amt is < 0, then we have overpassed the amout, return -1
 *
 */
int coinChange_memo(vector<int>& coins, int amount, vector<int>& dp) {
    if (amount < 0) {
        // Minimum no of coins required to make change for negative amount is -1
        return -1;
    }

    if (amount == 0) {
        // Minimum no of coins required to make change for amount 0 is 0
        return 0;
    }

    // If we have already calculated the minimum no of coins for the amount
    // return
    if (dp[amount] != 0) {
        return dp[amount];
    }

    // Not calculated yet. Try each coin to see if whether that makes the amount
    int minChange = INT_MAX;
    for (int coin : coins) {
        int changeResult = -1;
        if (coin <= amount) {
            changeResult = coinChange_memo(coins, amount - coin, dp);
        }

        /* If changeResult >= 0 and change result beats our present minimum, add one
           to that smallest value */
        if (changeResult >= 0 && changeResult < minChange) {
            minChange = 1 + changeResult;
        }
    }
    dp[amount] = minChange == INT_MAX ? -1 : minChange;

    return dp[amount];
}

int coinChange(vector<int>& coins, int amount) {
    // dp array to store the results of subproblems ie.., no of coins required to make up
    // the amount. length of dp is amount + 1 where + 1 is for to have the case when the
    // amount is zero
    vector<int> dp(amount + 1);

    return coinChange_memo(coins, amount, dp);
}

/*
 * coinChange BottomUp solution
 * Since there are many overlapping subproblems in Recursive solution, and the Solution for the main problem
 * can ba attained if we have solutions of suproblems, Dynamic Programming can be applied.
 *
 * Dynamic Programming Bottom up solution, conditions are similar to recursive but the intemediate results are
 * stored in a dp table. Bottom up is to find bottom solutions first to yield the top solution i.e.., solution of
 * the problem
 *
 * The Dp table is of lenght amount + 1 where +1 is for to have the case when the amount is zero
 * and holds the no.of coins required for the amount at i
 *
 * As the min no of coins required to make up the amount, initialize the dp array with a maximum value
 * i.e.., INT_MAX or amount + 1
 *
 * Eg: coins = [1, 2, 5] amount = 11;
 * For each amt i in dp, loop all the coins and find the min no of coins required to make the amount
 * For amt i in dp ranging from i =0 .... 11 and j in coins ranging from 0... coins.size()-1
 *    dp[i] = std::min (dp[i] - dp[i - coins[j]] + 1) only when i >= coins[j]

 * Base cases:
 * When the amt is zero no coins are required
 */
int coinChange_BU(vector<int>& coins, int amount) {
    // dp array to store the results of subproblems ie.., no of coins required to make up
    // the amount. length of dp is amount + 1 where + 1 is for to have the case when the
    // amount is zero.
    // Initialize the dp with max value i.e.., amount + 1
    vector<int> dp(amount + 1, amount + 1);

    // no coins are required to make up the amount 0
    dp[0] = 0;

    // Loop for all amounts and find the minimum no of coins required to make up the amount
    for (int amt = 1; amt < dp.size(); amt++) {
        // Loop all to coinst to see whether the min coins to make up the amount
        for (int coin : coins) {
            if (coin <= amt) {
                dp[amt] = std::min(dp[amt], dp[amt - coin] + 1);
            }
        }
    }

    return dp[amount];
}
