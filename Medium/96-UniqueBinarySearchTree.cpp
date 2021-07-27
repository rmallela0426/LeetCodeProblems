
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 96: Unique Binary Search Tree
 *
 * Given an integer n, return the number of structurally unique BST's (binary search trees)
 * which has exactly n nodes of unique values from 1 to n.
 *
 * Example 1:
 * Input: n = 3
 * Output: 5
 *
 * Example 2:
 * Input: n = 1
 * Output: 1
 *
 * Constraints:
 * 1 <= n <= 19
*/
/*
 * Approach followed is a dynamic programming solution.
 * Since only n is given to find the unique search trees from 1 to n,
 * we need to get a mathematical equation which helps to solve the
 * problem easily.
 *
 * For i = 1 ... n, each value of i should be at the root
 * n = 0, there will be only empty set {} => 1 unique combination
 * n = 1, there will be only one node {1} => 1 unique combination
 * n = 2, then there will be two nodes to work on {1, 2}
 *        1 on root => 1     2 on root => 2
 *                    / \                / \ => 2 unique combinations
 *                  {0} {2}            {1} {0}
 * From above we can see that when 1 is on root, 0 nodes on left subtree
 * and 1 node on the right subtree. Already the subproblems of n = 1 and
 * n = 0 are already evaluated => 1(when n = 0) * 1(when n = 1)
 *                              + 1(when n = 1) * 1(when n = 0)
 *
 * n = 3, then there will be 3 nodes to work on {1, 2, 3}
 *       1 on root =>  1     2 on root =>   2    3 on root =>   3
 *                    / \                  / \                 /  \
 *                  {0} {2,3}            {1} {3}            {1,2} {0}
 *
 * From above, when 1 at root, there won't be any node on left subtree and
 *                             2 nodes on right subtree
 *                 => num of combinations at left subtree *
 *                    num of combinations at right subtree
 *                 => 1(left subtree) * 2(right subtree)
 *             when 2 at root, there will be only 1 node at left and right
 *                 => 1(left subtree) * 1(right subtree)
 *             when 3 at root, there will be 2 nodes on left subtree and
 *                             there won't be any nodes on right subtree
 *                 => 2(left subtree) * 1(right subtree)
 *
 * Overall in general numTress(n) = numTrees(1) + numTrees(2)+....+ numTrees(n)
 *                 = summation(numTrees(i -1) * numTrees(n - i)) i = 0....n
 * Eg:
 * n = 4 =  numTrees(0) * numTrees(3) (i = 1) +
 *          numTrees(1) * numTrees(2) (i = 2) +
 *          numTrees(2) * numTrees(1) (i = 3) +
 *          numTrees(3) * numTrees(0) (i = 4)
 *
 * BaseCase:
 * . When n = 0 or 1, num Unique Trees = 1
 *
 * As there many duplication subproblems, and solution of the problem can be
 * obtained from solutions subproblems, dynamic programming approach is used
 * where the intermediate results are stored in a map
*/
// Map to store the unique binary search trees at that n
map<int, int> mp;

int numTrees(int n) {
    // Basecase: when n = 0 or 1
    if(n == 0 || n == 1) {
        // n is either 0 or 1 ie..., either empty nodes or 1 ndoe
        return mp[n] = 1;
    }

    // Check if this subproblem is already evaluated
    if (mp.count(n)) {
        // Subproblem is already evaluated, return the no of unique ways BST
        // can be generated
        return mp[n];
    }

    // Count variable to keep track of no of ways
    int count = 0;

    // Traverse the loop from 1 to n
    for (int i = 1; i <= n; i++) {
        // Evaluate the nodes when the current i is at root
        count += numTrees(i - 1) * numTrees(n - i);
    }

    // save the solution of this subproblem in the map for future use
    return mp[n] = count;
}
