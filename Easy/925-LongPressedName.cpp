
/*
*  Author: Raghavendra Mallela
*/

/*
Problem Statement:
LeetCode 925 : Long Pressed Name

Your friend is typing his name into a keyboard. Sometimes, when typing a character c,
the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard. Return True if it is possible that
it was your friends name, with some characters (possibly none) being long pressed.

Example 1:
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:
Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.

Example 3:
Input: name = "leelee", typed = "lleeelee"
Output: true

Example 4:
Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character
*/

bool isLongPressedName(string name, string typed) {
    if (name.length() > typed.length()) {
        // case when the typed is smaller than the name.
        // in this case it is false
        return false;
    }

    /* 2 Pointer approach */

    // Index of string name
    int idxS = 0;
    // Index of string typed
    int idxT = 0;

    // Loop until idxS reach complete name. 
    while (idxS < name.length()) {
        if (name[idxS] == typed[idxT]) {
            // If both chars are matching, then remaining string
            // needs to be checked.
            idxS++;
            idxT++;
        }
        else if (idxT != 0 && typed[idxT - 1] == typed[idxT]) {
            // If the previous char matches in the typed matches,
            // procced to next char in typed
            idxT++;
        }
        else {
            // Char doesn't match i.e.., it is not in the name
            return false;
        }
    }

    // Run throught the remaining elements in typed
    for (; idxT < typed.length(); idxT++) {
        if (typed[idxT] != typed[idxT - 1])
            return false;
    }

    return true;
}
