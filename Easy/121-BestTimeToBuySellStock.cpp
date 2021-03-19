
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 121: Best Time to Buy And Sell Stocks
 *
 * You are given an array prices where prices[i] is the price of a given stock on
 * the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and
 * choosing a different day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you cannot
 * achieve any profit, return 0.
 *
 * Example 1:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
 *
 * Example 2:
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit = 0.
 *
 * Constraints:
 * 1 <= prices.length <= 105
 * 0 <= prices[i] <= 104
*/
/*
 * As the solution is to find the max profit by buying a
 * stock on a single day and different day in future to
 * sell the stock with the given prices of stock at each
 * day, need to see if the current day is less than the
 * previous day, then buying a stock on that day gives
 * loss.
 * Eg: 7, 1, 5, 3, 6, 4
 * If the stock is bought on day 0 and sell it on day 1,
 * then net loss is 1 - 7 = -6
 * If the stock is bought on day 1 and sell it on day 2,
 * then net profit is 5 - 1 = 4
 *
 * Algorithm followed is peak and valleys where the values
 * are plotted on graph and finding the largest peak following
 * the smallest valley.
*/
int maxProfit(vector<int>& prices) {
    if (prices.empty())
        return 0;

    int minprice = INT_MAX;
    int maxprofit = 0;

    for (int price : prices) {
        if (price < minprice)
            minprice = price;
        if (price - minprice > maxprofit)
            maxprofit = price - minprice;
    }
    return maxprofit;
}
