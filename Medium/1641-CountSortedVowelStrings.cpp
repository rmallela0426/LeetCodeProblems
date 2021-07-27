
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1641: Count Sorted Vowel Strings
 *
 * Given an integer n, return the number of strings of length n that consist
 * only of vowels (a, e, i, o, u) and are lexicographically sorted.
 * A string s is lexicographically sorted if for all valid i, s[i] is the same
 * as or comes before s[i+1] in the alphabet.
 *
 * Example 1:
 * Input: n = 1
 * Output: 5
 * Explanation: The 5 sorted strings that consist of vowels only are
 *              ["a","e","i","o","u"].
 *
 * Example 2:
 * Input: n = 2
 * Output: 15
 * Explanation: The 15 sorted strings that consist of vowels only are
 * ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
 * Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
 *
 * Example 3:
 * Input: n = 33
 * Output: 66045
 *
 * Constraints:
 * 1 <= n <= 50 
*/
/*
 * Approach followed is backtracking method to count the
 * number of vowels strings.
*/
void countVowelStrings(int n, int startidx, int& numVowelStrings) {
    // BaseCase: If  n is zero ie.., a vowel string is generated
    // of given lenght n
    if (n == 0) {
        // n length vowel string is generated, increment the count
        numVowelStrings++;
        return;
    }

    // Traverse for all vowels and generate the strings
    // As there are 5 vowels, loop for 5 from the starting index
    for (int i = startidx; i < 5; i++) {
        // Generate all strings with the current vowel char by considering
        // the current char
        countVowelStrings(n - 1, i, numVowelStrings);
    }

    // Done with all strings
    return;
}

int countVowelStrings(int n) {
    int res = 0;

    countVowelStrings(n, 0, res);

    return res;
}

/*
 * Recursive solution:
 * As the strings generated should be lexigraphically sorted
 * we can include the current char and reduce the length so
 * that "aaa..." will be generated + proceding to next char
 * by not reducing the length "aei...."
 * vowels = "aeiou" = 5
 *   countVowelString(numVowels, n - 1) +
 *   countVowelString(numVowel - 1, n)
 *
 * If we draw a tree structure there will be many duplicate
 * subproblems and the solution to the problem can be obtained
 * from solutions of subproblem, dynmaic programming can be used.
 *
 * When n = 1, string formed are  a e i o u  => 5
 * when n = 2,
 *  strings formed startign with a are aa, ae, ai, ao, au => 5
 *  strings formed starting with e are ee, ei, eo, eu => 4
 *  strings formed starting with i are ii, io, iu => 3
 *  strings formed starting with o are oo, ou => 2
 *  strings formed starting with u are uu => 1
 * Total sorted lexicographically strings with length 2 is
 *             5 + 4 + 3+ 2 + 1 = 15
 * when n = 3,
 *  strings formed starting with u are uuu => 1
 *  strings formed starting with o are ooo, oou, ouu => 3
 *   ie.., strings formed with 'o' when lenght = 2 + stirngs with 'u'
 *  strings formed starting with i are iii, iio, iiu
 *                                     ioo, iou
 *                                     iuu  => 3 + 2 + 1 = 5
 *
 * we can see a pattern from above where the number of strings that
 * are formed from previous row + current row next column
 *
 * A dp table of num vowels is 5
 *                 a  e   i   o   u
 * when n = 1  =>  1  1   1   1   1
 *                   \   \   \   \
 *      n = 2  =>  5   4  3   2   1
 *                   \   \   \   \
 *      n = 3  => 15   10  6   3   1
 *
 *     dp[i] = dp[i] + dp[i + 1] where i = n - 2 to 0
*/

int countVowelStrings(int n) {
    // Basecase: when n is zero
    if (n == 0) {
        // length of strings is zero, no strings are generated
        return 0;
    }

    // dp table to store the total of strings that are generated with
    // current char
    // Initialize the array with 1 as the strings formed with n = 1
    vector<int> dp(5, 1);

    // Traverse the loop from length 2 to n
    for (int i = 2; i <= n; i++) {
        // Find the total no of strings for the length i
        // As there will be only 1 string can be formed with u is always
        // 1, traverse from vowel 'o' to 'a'
        for (int j = 3; j >= 0; j--) {
            // Calculate the strigs that cna be formed with the current vowel
            dp[j] = dp[j] + dp[j + 1];
        }
    }

    // Now that we got the number of strings starting with each char, accumulate
    // to get the total number of strings
    return accumulate(dp.begin(), dp.end(), 0);
}
