

/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1220: Count Vowels Permutation
 *
 * Given an integer n, your task is to count how many strings of length n can be formed under
 * the following rules:
 *
 * Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
 * Each vowel 'a' may only be followed by an 'e'.
 * Each vowel 'e' may only be followed by an 'a' or an 'i'.
 * Each vowel 'i' may not be followed by another 'i'.
 * Each vowel 'o' may only be followed by an 'i' or a 'u'.
 * Each vowel 'u' may only be followed by an 'a'.
 * Since the answer may be too large, return it modulo 10^9 + 7.
 *
 * Example 1:
 * Input: n = 1
 * Output: 5
 * Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
 *
 * Example 2:
 * Input: n = 2
 * Output: 10
 * Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua"
 *
 * Example 3:
 * Input: n = 5
 * Output: 68
 *
 * Constraints:
 * 1 <= n <= 2 * 10^4
*/

/*
 * As we need to find the no of permutation strings of length n,
 * not the permutations, approach followed is a dynamic programming
 * solution.
 * For n = 1, the strigs that can be formed are a, e, i, o, u ie..,
 * 5. If we have the previous solution, we can generate the current
 * strings ie.., if the current char is a then next char will be e.
 *
 * As the current solution is evaluated from previous solutions, the
 * approach followed is a Bottom Up solution where 2 arrays of length
 * 5(as there are 5 vowels) is initialized previous and current. The
 * previous array holds no of strings that a char can generate. Based
 * on previous, the current strings will be generated.
 *
 * Base case: when n = 1, all the previous array will be 1.
*/
int countVowelPermutation(int n) {
    // If n is 1
    if (n == 1) {
        // The number of strings that can be formed when length of stirng
        // is 1, then no of strings will be 5
        return 5;
    }

    // Mod value
    int MOD = 1000000007;

    // Initialize the previous array and current array of size 5
    vector<int> previous(5, 0);
    vector<int> current(5, 0);

    // Fill the previous array when n is 1
    for (int i = 0; i < 5; i++) {
        previous[i] = 1;
    }

    // Traverse the loop till we generate strings of length n
    for (int i = 1; i < n; i++) {
        // Generate the current array based on conditions specified in the
        // problem
        // If the current char is 'a' it should be followed by 'e' ie.., the
        // combination of strings that can be formed
        current[0] = previous[1];

        // If the current char is 'e' it should be followed by either 'a' or
        // "i"
        current[1] = (previous[0] + previous[2]) % MOD;

        // If the current char is 'i' it should be followed by either 'a', 'e'
        // 'o', 'u'
        long sum = (long)previous[0] + (long)previous[1] + (long)previous[3] + (long)previous[4];
        current[2] = sum % MOD;

        // If the current char is 'o' it should be followed by either 'i' or 'u'
        current[3] = (previous[2] + previous[4]) % MOD;

        // If the current char is 'u' is should be followed by 'a'
        current[4] = previous[0] % MOD;

        // copy the current to previous
        previous = current;
    }


    // Total no of strings is sum of strings formed by individual chars
    long sum = (long)current[0] + (long)current[1] + (long)current[2] + (long)current[3] + (long)current[4];
    return sum % MOD;
}
