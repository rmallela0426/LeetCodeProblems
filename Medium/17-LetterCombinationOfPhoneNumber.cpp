

/*
 * LeetCode 17: Letter Cobination Of a Phone Number
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *  2 -> "abc" 3 -> "def" 4 -> "ghi" 5 -> "jkl"
 *  6 -> "mno" 7 -> "pqrs" 8 -> "tuv" 9 -> "wxyz"
 *
 * Example 1:
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 * Example 2:
 * Input: digits = ""
 * Output: []
 *
 * Example 3:
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 * Constraints:
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
*/
/*
 * Approach followed is DFS where each letter in the digit is
 * taken inorder to a single combination
*/

// String to store the map the chars that are at a particular digit
// 0 & 1 doesn't corresponds to any letters
string mp[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

// Vector to store the result of the string
vector<string> res;

// dfs function that combines each combination of a digit
void dfs(string& digits, int idx, string& combine) {
    // Check if all digits are done
    if (idx >= digits.length()) {
        // All the digits are done and there is a letter
        // combination, add it to result
        res.push_back(combine);

        return;
    }

    // Retrieve the letters at particular digit
    string letters = mp[digits[idx] - '0'];

    // Loop on characters in the letters
    for (char ch : letters) {
        // Add the current letter to combine string
        combine += ch;

        // Repeat for all digits in the input string
        dfs(digits, idx + 1, combine);

        // Remove the last character from the combination as we are done
        // with that letter
        combine.pop_back();
    }

    return;
}

vector<string> letterCombinations(string digits) {
    // check if string is empty
    if (digits.empty()) {
        return res;
    }

    string combine = "";
    dfs(digits, 0, combine);

    return res;
}
