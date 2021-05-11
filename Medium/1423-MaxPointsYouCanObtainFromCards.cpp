
/*
 * Author: Raghavendra Mallela
*/
/*
 * LeetCode 1423: Max Points You Can Obtain from Cards
 *
 * There are several cards arranged in a row, and each card has an associated number
 * of points The points are given in the integer array cardPoints.
 * In one step, you can take one card from the beginning or from the end of the row.
 * You have to take exactly k cards.
 *
 * Your score is the sum of the points of the cards you have taken.
 * Given the integer array cardPoints and the integer k, return the maximum score you
 * can obtain.
 *
 * Example 1:
 * Input: cardPoints = [1,2,3,4,5,6,1], k = 3
 * Output: 12
 * Explanation: After the first step, your score will always be 1. However, choosing
 * the rightmost card first will maximize your total score. The optimal strategy is to
 * take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
 *
 * Example 2:
 * Input: cardPoints = [2,2,2], k = 2
 * Output: 4
 * Explanation: Regardless of which two cards you take, your score will always be 4.
 *
 * Example 3:
 * Input: cardPoints = [9,7,7,9,7,7,9], k = 7
 * Output: 55
 * Explanation: You have to take all the cards. Your score is the sum of points of all
 * cards.
 *
 * Example 4:
 * Input: cardPoints = [1,1000,1], k = 1
 * Output: 1
 * Explanation: You cannot take the card in the middle. Your best score is 1.
 *
 * Example 5:
 * Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
 * Output: 202
 *
 * Constraints:
 * 1 <= cardPoints.length <= 10^5
 * 1 <= cardPoints[i] <= 10^4
 * 1 <= k <= cardPoints.length
*/
/*
 * Approach followed is a sliding window technique where total
 * sum of the input cardPoints is calculated and find max answer
 * using the window of remaining elements by removing the sum.
*/
int maxScore(vector<int>& cardPoints, int k) {
    // Check if the input vector is empty
    if (cardPoints.empty()) {
        // CardPoints is empty,
        return 0;
    }

    int totalPts = 0;

    // Loop all the cards and find total points
    for (int points : cardPoints) {
        totalPts += points;
    }

    // Check if all the points are needed ie.., k == cardPoints.size
    if (k == cardPoints.size()) {
        // All the points are needed, return the size
        return totalPts;
    }

    // Sliding widow
    int wndStart = 0; int wndEnd = 0;
    int wndSize = cardPoints.size() - k;
    int wndSum = 0;
    // Variable to store the max Score of points
    int maxScore = INT_MIN;

    // Loop while we reach the end of the window
    while (wndEnd < cardPoints.size()) {
        // Calculate the wnd sum
        wndSum += cardPoints[wndEnd];

        // Check if we reach the window size
        if (wndEnd - wndStart + 1 == wndSize) {
            // Find the max score
            maxScore = max(maxScore, totalPts - wndSum);

            // Move the window to right
            // Remove the window start element from wndSum
            wndSum -= cardPoints[wndStart];
            wndStart++;
        }
        wndEnd++;
    }

    return maxScore;
}
