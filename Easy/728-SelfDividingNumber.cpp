
/*
 * Author: Raghavendra Mallela
*/
/*
 * LeetCode 728: Self Dividing Number
 *
 * A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
*/
vector<int> selfDividingNumbers(int left, int right) {
    // vector to store the self diving numbers
    vector<int> res;

    // temp variables
    int num;
    int digit;

    // loop for all values in the rage of left and right
    for (int i = left; i <= right; i++) {
        // check whether left is a self dividing number
        num = i;

        // Loop to all digits and check whether the i can be
        // divisible by every digit
        while (num > 0) {
            // retrieve last digit
            digit = num % 10;

            // Check if digit is zero and wether num is divisible by digit
            if (digit == 0 || i % digit != 0) {
                // digit is either zero or the num is not divisibel by
                // digit, break
                break;
            }
            num = num / 10;
        }

        if (num == 0) {
            // num is zero that means it a self diving number
            res.push_back(i);
        }
    }

    return res;
}
