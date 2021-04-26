
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1773: Count Items Matching a Rule
 *
 * You are given an array items, where each items[i] = [typei, colori, namei] describes
 * the type, color, and name of the ith item. You are also given a rule represented by
 * two strings, ruleKey and ruleValue.
 *
 * The ith item is said to match the rule if one of the following is true:
 * ruleKey == "type" and ruleValue == typei.
 * ruleKey == "color" and ruleValue == colori.
 * ruleKey == "name" and ruleValue == namei.
 * Return the number of items that match the given rule.
 *
 * Example 1:
 * Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]],
 *        ruleKey = "color", ruleValue = "silver"
 * Output: 1
 * Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
 *
 * Example 2:
 * Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]],
 *        ruleKey = "type", ruleValue = "phone"
 * Output: 2
 * Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"]
 * and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.
 *
 * Constraints:
 * 1 <= items.length <= 104
 * 1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
 * ruleKey is equal to either "type", "color", or "name".
 * All strings consist only of lowercase letters.
*/
int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    // Generate the index based on the ruleKey
    // Intialize the index that points to type of the item
    int idx = 0;
    if (ruleKey == "color") {
        // Update the index to point to color of the item
        idx = 1;
    }
    else if (ruleKey == "name") {
        // Update the index to point to name of the item
        idx = 2;
    }

    // Variable to store num of items that match ruleValue
    int count = 0;

    // Loop for all the items in the input vector
    for (vector<string>& item : items) {
        if (item[idx] == ruleValue)
            count++;
    }

    return count;
}
