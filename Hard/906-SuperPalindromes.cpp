
/*
 * Author: Raghavendra Mallela
*/

/*
 * LeetCode 906: Super Palindromes
 *
 * Let's say a positive integer is a super-palindrome if it is a
 * palindrome, and it is also the square of a palindrome.
 *
 * Given two positive integers left and right represented as strings,
 * return the number of super-palindromes integers in the inclusive
 * range [left, right].
 *
 * Example 1:
 * Input: left = "4", right = "1000"
 * Output: 4
 * Explanation: 4, 9, 121, and 484 are superpalindromes.
 * Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is
 * not a palindrome.
 *
 * Example 2:
 * Input: left = "1", right = "2"
 * Output: 1
 *
 * Constraints:
 * 1 <= left.length, right.length <= 18
 * left and right consist of only digits.
 * left and right cannot have leading zeros.
 * left and right represent integers in the range [1, 1018].
 * left is less than or equal to right.
*/
/*
 * Approach is to create even and odd palindromes from 1 to 100000
 * and check whether their squares are palidromes.
 * Super palindrome is a positive integer wheter it is a palindrome
 * it is also the square of the palindrome i.e...,
 *       S = R^2   =>  1 -> 1, 2 -> 4, 3 -> 9, 11 -> 121, 22 -> 484
 * Since super palindromes are in range of 10^18, the R should be in
 * the range of 10^9. Find all palindromes between the range and check
 * if their squares are palindromes.
 *
 * step 1: Find all Palindromes between the range 1 to 10^9
 * To do this, either find or create the palindromes in 1 to 10^ 9.
 * Finding Palindromes is little tricky because needs to be looped,
 * and find all palindromes in that range.
 * So considering creation of Palindromes in the range 1 to 10^9
 *   There could be 2 types of palindromes
 *          . Even Length Palindromes -> eg: 1221
 *          . Odd Length Palindromes  -> eg: 12321
 * For even Length palindromes length eg: 1221, we take 12 and reverse
 * it and append it to the input 12 ie.. the range now reduced to further
 * half ie.., 10^5.
 *
*/
bool isPalindrome(long long int num) {
    long long int rev = 0, temp = num;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == num;
}

int superpalindromesInRange(string left, string right) {
    // Generate the range values from input string
    long long int l = stol(left);
    long long int r = stol(right);

    long long int sqrt_l = sqrt(l);
    long long int sqrt_r = sqrt(r);

    // Variable to store the numSuperPalindromes
    int numSP = 0;

    // Generate even & odd Palindromes in range of 1 to right
    for (int i = 1; i <= sqrt_r; i++) {
        string even = to_string(i);
        string odd = to_string(i);

        // Generate the even palindrome by appending the reverse of the string
        even.append(even.rbegin(), even.rend());
        // Generate the odd Palindrome by excluding the last character and appending
        odd.append((odd.rbegin() + 1), odd.rend());

        // Palindrome number of even length
        long long int num_e = stol(even);
        // Palindrome number of odd length
        long long int num_o = stol(odd);

        // Chek the square the generated number is a palindrome or not
        if (num_e >= sqrt_l && num_e <= sqrt_r && isPalindrome(num_e * num_e)) {
            // Square is also palindrome i.e.., number is super palindrome
            numSP++;
        }
        // Chek the square the generated number is a palindrome or not
        if (num_o >= sqrt_l && num_o <= sqrt_r && isPalindrome(num_o * num_o)) {
            // Square is also palindrome i.e.., number is super palindrome
            numSP++;
        }

        // Check if both even num and odd num are exceeding the right bound
        if (num_e > sqrt_r && num_o > sqrt_r) {
            // num_e & num_o are greater than right bound, no need to procced further
            break;
        }
    }
    return numSP;
}
