
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 341: Flatten Nested List Iterator
 *
 * You are given a nested list of integers nestedList. Each element is either an
 * integer or a list whose elements may also be integers or other lists. Implement
 * an iterator to flatten it.
 *
 * Implement the NestedIterator class:
 *   NestedIterator(List<NestedInteger> nestedList) - Initializes the iterator with
 *                                                    the nested list nestedList.
 *   int next()  - Returns the next integer in the nested list.
 *   boolean hasNext() - Returns true if there are still some integers in the nested
 *                       list and false otherwise.
 *
 * Example 1:
 * Input: nestedList = [[1,1],2,[1,1]]
 * Output: [1,1,2,1,1]
 * Explanation: By calling next repeatedly until hasNext returns false, the order of
 *             elements returned by next should be: [1,1,2,1,1].
 *
 * Example 2:
 * Input: nestedList = [1,[4,[6]]]
 * Output: [1,4,6]
 * Explanation: By calling next repeatedly until hasNext returns false, the order of
 *             elements returned by next should be: [1,4,6].
 *
 * Constraints:
 * 1 <= nestedList.length <= 500
 * The values of the integers in the nested list is in the range [-106, 106].
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

 /*
  * Approach is to flatten the input vector and store the integers
  * in a vector during the constructor using the helper methods in
  * Nested Integer class.
 */
class NestedIterator {
private:
    // Vector to store the flatten list
    vector<int> list;
    // Index for the current int that is available
    int idx;

    // Method that parses the input list and flattens it
    void flattenList(vector<NestedInteger>& nestedList) {
        for (NestedInteger& curr : nestedList) {
            // Check if the current list holds a single integer or a nested list
            // If single integer, retrieve the integer and save it to list, else
            // loop the nested list and save individual elements
            curr.isInteger() ? list.push_back(curr.getInteger()) : flattenList(curr.getList());
        }
        return;
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Flatten the list
        flattenList(nestedList);
        // Initialize the curr index to access the first element
        idx = 0;
    }

    int next() {
        // Check if we are done with all elements, if not return
        // the current element, else return null
        return idx < list.size() ? list[idx++] : NULL;
    }

    bool hasNext() {
        // Check if are done with all elements in the list
        return idx < list.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
