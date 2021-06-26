
/*
 *  Author: Raghavendra Mallela
*/
/*
 *  LeetCode 1324: Print Words Vertically
 *
 * Given a string s. Return all the words vertically in the same order in which
 * they appear in s.
 * Words are returned as a list of strings, complete with spaces when is necessary.
 * (Trailing spaces are not allowed).
 * Each word would be put on only one column and that in one column there will be
 * only one word.
 *
 * Example 1:
 * Input: s = "HOW ARE YOU"
 * Output: ["HAY","ORO","WEU"]
 * Explanation: Each word is printed vertically. 
 *       "HAY"
 *       "ORO"
 *       "WEU"
 *
 * Example 2:
 * Input: s = "TO BE OR NOT TO BE"
 * Output: ["TBONTB","OEROOE","   T"]
 * Explanation: Trailing spaces is not allowed.
 *      "TBONTB"
 *      "OEROOE"
 *      "   T"
 *
 * Example 3:
 * Input: s = "CONTEST IS COMING"
 * Output: ["CIC","OSO","N M","T I","E N","S G","T"]
 *
 * Constraints:
 * 1 <= s.length <= 200
 * s contains only upper case English letters.
 * It's guaranteed that there is only one space between 2 words.
*/
/*
 * Approach followed is a brute force
 *
 *  . Retrieve the words based on space and save it in a vector
 *  . Get the max length of the all the words in the strings
 *  . Traverse the loop from 0 to maxlenght and pull the current
 *    char from each word
 *  . Remove trailing spaces
*/
vector<string> printVertically(string s) {
    // vector to store the words vertically
    vector<string> res;

    // Base case to check whether input string is empty or not
    if (s.empty()) {
        // input string is empty, no words
        return res;
    }

    // vector to store the words present in input string
    vector<string> words;
    // Maxlength of the word
    int maxlength = 0;

    // Assign the word to string stream
    stringstream ss(s);

    // Extract the words
    while (ss >> s) {
        // Got a word, calculate the max length
        maxlength = max(maxlength, (int)s.length());
        // push the word to the vector of words
        words.push_back(s);
    }

    // Extract the words vertically, traverse the max length of word
    for (int i = 0; i < maxlength; i++) {
        // vertical word
        s = "";

        // Traverse each word from input, extract the current char and
        // add it to vertical word, if word size is less than the current
        // index put an empty space
        for (string& word : words) {
            // Check if there is a char in the current index
            // if present add char to vertical word, else add an empty space
            s += i < word.length() ? word[i] : ' ';
        }

        // Remove the trailing spaces if any in the vertical word
        while (s.back() == ' ') {
            s.pop_back();
        }

        // Push the vertical word to result
        res.push_back(s);
    }


    return res;
}
