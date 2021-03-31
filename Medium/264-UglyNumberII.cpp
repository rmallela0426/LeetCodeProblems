
/*
 * Leetcode 264: Ugly Number II
 *
 * Given an integer n, return the nth ugly number.
 * Ugly number is a positive number whose prime factors only include 2, 3, and/or 5.
 *
 * Example 1:
 * Input: n = 10
 * Output: 12
 * Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first
 * 10 ugly numbers.
 *
 * Example 2:
 * Input: n = 1
 * Output: 1
 * Explanation: 1 is typically treated as an ugly number.
*/
/* An ugly number is the one whose prime factors are in the
  * set of {2, 3, 5}
  * Eg: n = 10
  *    [1,2,3,4,5,6,8,9,10,12] = 12
  *
  * Pseudo code:
  * 1 is already an ugly number and start with 2
  * check if it is ugly or not. If ugly increment the count
  * Increment the number
  * return the nth ugly number
  *
  * TimeComplexity: O(NLogN)
  * SpaceComplexity: O(1)
 */
int nthUglyNumber(int n) {

    // 1 is already ugly start with 1
    int num = 1;
    int count = 1;

    while (count < n) {
        // Increment the num so that it will be start at 2 in
        // beginining
        num++;

        int temp = num;
        // checking whether the number is palindrome or not
        // Check if the number is divisible by 2, 3, 5
        // If so the result will be 1 where 1 is always
        // an ugly number
        for (int factor : {2, 3, 5}) {
            while (temp % factor == 0) {
                temp = temp / factor;
            }
        }
        count += temp == 1;
    }

    // num points to the nth ugly number
    return num;
}

/* An ugly number is the one whose prime factors are in the
* set of {2, 3, 5}
* Eg: n = 10
*    [1,2,3,4,5,6,8,9,10,12] = 12
*
* Dynamic programming:
* Approach is to find the min of multiples of 2, 3, 5 for
* every i(1... n)
*
* PseudoCode:
*  . Create a ugly table of size n that holds the ugly numbers
*    till n
*  . Fill the 0th element with 1 as it is known ugly number
*  . Initialize 3 variables that points to idx of dp table,
*    for multiple of 2,3,5
*       i2 = i3 = i5 = 0
*  . Initialize 3 choices of the next multiples
*       next_multiple_of_2 = ugly[i2] * 2
*       next_multiple_of_3 = ugly[i3] * 3
*       next_multiple_of_5 = ugly[i5] * 5
*  . Start filling the ugly table
*  . Return the last element of the array
*
* TimeComplexity: O(N)
* SpaceComplexity: O(N)
*/

int nthUglyNumber(int n) {
    if (n == 1) {
        // 1 is alway ugly
        return 1;
    }

    // Table of lenght n that stores the ugly numbers
    vector<int> ugly(n, 0);
    // store the 0th element with 1
    ugly[0] = 1;

    // idx to store the next 3 multiples
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    //  variables to store the next 3 multiples
    int next_multiple_of_2 = ugly[i2] << 1;
    int next_multiple_of_3 = ugly[i3] * 3;
    int next_multiple_of_5 = ugly[i5] * 5;

    // Fill the ugly table
    for (int i = 1; i < ugly.size(); i++) {
        // Find the min of 3 next multiplies and that is the ith
        // ugly number
        int num = std::min(next_multiple_of_2, std::min(next_multiple_of_3, next_multiple_of_5));
        // store it int he ugly table
        ugly[i] = num;

        // update the next multiples of the 3 choices
        if (num == next_multiple_of_2) {
            i2++;
            next_multiple_of_2 = ugly[i2] << 1;
        }
        if (num == next_multiple_of_3) {
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (num == next_multiple_of_5) {
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }

    // return the last num in the ugly array
    return ugly.back();
}