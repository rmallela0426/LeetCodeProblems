
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 575: Distribute Candies
 *
 * Alice has n candies, where the ith candy is of type candyType[i].
 * Alice noticed that she started to gain weight, so she visited a doctor.
 *
 * The doctor advised Alice to only eat n / 2 of the candies she has (n 
 * is always even). Alice likes her candies very much, and she wants to
 * eat the maximum number of different types of candies while still following
 * the doctor's advice.
 * Given the integer array candyType of length n, return the maximum number
 * of different types of candies she can eat if she only eats n / 2 of them.
 *
 * Example 1:
 * Input: candyType = [1,1,2,2,3,3]
 * Output: 3
 * Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3
 *              types, she can eat one of each type.
 *
 * Example 2:
 * Input: candyType = [1,1,2,3]
 * Output: 2
 * Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types
 * [1,2], [1,3], or [2,3], she still can only eat 2 different types.
 *
 * Constraints:
 * n == candyType.length
 * 2 <= n <= 104
 * n is even.
 * -105 <= candyType[i] <= 105
*/
int distributeCandies(vector<int>& candyType) {
    // If the candyTypes are empty, return 0
    if (candyType.empty())
        return 0;

    // Max no of candies that can Alice eat
    int maxCandiesToEat = candyType.size() >> 1;

    // Sort the candyType array to get the no of types of candies
    std::sort(candyType.begin(), candyType.end());

    // Count num of types of candies, as all the same type is in
    // order, increment the numTypes if there is a different candy
    // type.
    int type0 = candyType[0];
    int numCandyTypes = 1;

    for (int i = 1; i < candyType.size(); i++) {
        if (candyType[i] != candyType[i - 1])
            numCandyTypes++;
    }

    return numCandyTypes > maxCandiesToEat ? maxCandiesToEat : numCandyTypes;
}
