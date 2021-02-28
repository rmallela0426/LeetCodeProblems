
/*
*  Author: Raghavendra Mallela
*/

/*
 * LeetCode 771: Jewels and Stones
 * You're given strings jewels representing the types of stones that are jewels,
 * and stones representing the stones you have. Each character in stones is a type
 * of stone you have. You want to know how many of the stones you have are also jewels.
 *
 * Letters are case sensitive, so "a" is considered a different type of stone from "A".
 *
 * Example 1:
 * Input: jewels = "aA", stones = "aAAbbbb"
 * Output: 3
 *
 * Example 2:
 * Input: jewels = "z", stones = "ZZ"
 * Output: 0
 *
 * Constraints:
 * 1 <= jewels.length, stones.length <= 50
 * jewels and stones consist of only English letters.
 * All the characters of jewels are unique.
*/

/* Approach is to loop all stones and check each
 * stone is present in Jewel. If so, increment the count.
*/

int numJewelsInStones(string J, string S) {
    // Count to store the no of Jewels in Stones
    int numJewels = 0;

    // Loop for all stones in S and check  if each is
    // present in Jewel.
    // If present 
    for (char stone : S) {
        if (J.find(stone) != std::string::npos)
            numJewels++;
    }

    return numJewels;
}