
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 936: Stamping The Sequence
 *
 * You want to form a target string of lowercase letters.
 * At the beginning, your sequence is target.length '?' marks.  You also have
 * a stamp of lowercase letters.
 * On each turn, you may place the stamp over the sequence, and replace every
 * letter in the sequence with the corresponding letter from the stamp.  You
 * can make up to 10 * target.length turns.
 *
 * For example, if the initial sequence is "?????", and your stamp is "abc",
 * then you may make "abc??", "?abc?", "??abc" in the first turn.  (Note that
 * the stamp must be fully contained in the boundaries of the sequence in order
 * to stamp.)
 * If the sequence is possible to stamp, then return an array of the index of
 * the left-most letter being stamped at each turn.  If the sequence is not
 * possible to stamp, return an empty array.
 * For example, if the sequence is "ababc", and the stamp is "abc", then we could
 * return the answer [0, 2], corresponding to the moves "?????" -> "abc??" -> "ababc".
 *
 * Also, if the sequence is possible to stamp, it is guaranteed it is possible to
 * stamp within 10 * target.length moves.  Any answers specifying more than this
 * number of moves will not be accepted.
 *
 * Example 1:
 * Input: stamp = "abc", target = "ababc"
 * Output: [0,2]
 * ([1,0,2] would also be accepted as an answer, as well as some other answers.)
 *
 * Example 2:
 * Input: stamp = "abca", target = "aabcaca"
 * Output: [3,0,1]
 * 
 * Note:
 * 1 <= stamp.length <= target.length <= 1000
 * stamp and target only contain lowercase letters.
*/
/*
 * Solution is to find whether the target is formed from a stamp.
 *
 * Approach followed is to check whether the substring of stamp length in
 * target is equal to stamp. If so replace it with '?'. '?' in substrings
 * are universal and can be replaced with any characters of stamp. Program
 * ends only when all chars in target are '?'.
 *
*/

// Method to replace the characters with '?' and updates the numReplaced Charactes
void replace(string& target, int& pos, int& numChars, int& numReplacedChars) {
    for (int i = pos; i < pos + numChars; i++) {
        if (target[i] != '?') {
            target[i] = '?';
            numReplacedChars += 1;
        }
    }
}

vector<int> movesToStamp(string stamp, string target) {
    int slength = stamp.size();
    int tlength = target.size();

    // vector to store the indices of the substrings
    vector<int> res;
    // Keeps track of the total num of characters that are
    // replaced with '?'
    int numReplacedChars = 0;

    // Loop until all the chars in target are replaced with '?'
    while (numReplacedChars < tlength) {
        int prevResSize = res.size();

        // Loop until there is a substring of stamp length
        for (int i = 0; i <= tlength - slength; i++) {
            auto itBegin = target.begin() + i, itEnd = itBegin + slength;

            // Check if we already visited this by checking whether the
            // substring has all '?'
            if (std::all_of(itBegin, itEnd, [](char c) {return c == '?'; }))
                continue;

            // Check if substring matches that of the stamp.
            // If there is a '?' char, then it universal ie.., can be replaced
            // with any of char
            int j = 0;
            for (; j < slength && (*(itBegin + j) == stamp[j] || *(itBegin + j) == '?'); j++);

            if (j == slength) {
                // Found a substring of stamp in target, replace with ''?''
                replace(target, i, slength, numReplacedChars);
                // Insert the starting index of the substring
                res.insert(res.begin(), i);
            }
        }

        // After running the entire loop, check if there are any substrings
        // or not. if not return empty array
        if (prevResSize == res.size()) {
            return {};
        }
    }
    return res;
}
