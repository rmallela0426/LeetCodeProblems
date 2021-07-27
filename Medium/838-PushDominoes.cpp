
/*
*  Author: Raghavendra Mallela
*/
/*
 * LeetCode 838: Push Dominoes
 *
 * There are n dominoes in a line, and we place each domino vertically upright.
 * In the beginning, we simultaneously push some of the dominoes either to the
 * left or to the right.
 *
 * After each second, each domino that is falling to the left pushes the adjacent
 * domino on the left. Similarly, the dominoes falling to the right push their
 * adjacent dominoes standing on the right.
 *
 * When a vertical domino has dominoes falling on it from both sides, it stays
 * still due to the balance of the forces.
 * For the purposes of this question, we will consider that a falling domino expends
 * no additional force to a falling or already fallen domino.
 *
 * You are given a string dominoes representing the initial state where:
 *    dominoes[i] = 'L', if the ith domino has been pushed to the left,
 *    dominoes[i] = 'R', if the ith domino has been pushed to the right, and
 *    dominoes[i] = '.', if the ith domino has not been pushed.
 * Return a string representing the final state.
 *
 * Example 1:
 * Input: dominoes = "RR.L"
 * Output: "RR.L"
 * Explanation: The first domino expends no additional force on the second domino.
 *
 * Example 2:
 * Input: dominoes = ".L.R...LR..L.."
 * Output: "LL.RR.LLRRLL.."
 *
 * Constraints:
 * n == dominoes.length
 * 1 <= n <= 105
 * dominoes[i] is either 'L', 'R', or '.'.
*/
/*
 * As the dominoes are in a line and placed vertically upright, if
 * the first dominoe falls right then 2nd dominoe also falls right
 * and so on. If the dominoe of last falls left, then the previous
 * dominoe also falls left. Since there is a case that when dominoe
 * has dominoes falling from left and right, then it stays there
 * vertically.
 * Since we need to see whether the dominoe stays still or not, we
 * need to traverse from both directions
 * . Left to Right and calculate the force when dominoe falls right.
 *   Eg: R......
 *   In above example, we can see that all the dominoes falls to right
 *   so, the force will be N in this case
 * . Right to Left and calcualte the force when dominoe falls left
 *   Eg: ......L
 *   Above example shows that when last dominoe falls left all the
 *   dominoes falls to left. so the force will be N and force will
 *   be reduced when traversing from right to left.
 *
 * . Traverse the force array that is calculated and check if force
 *   is positive then dominoe moved right, if the force is negative
 *   dominoe moved left and if force is 0, then dominoe si not pushed
 *
*/
string pushDominoes(string dominoes) {
    // Basecase: If the string is empty
    if (dominoes.empty()) {
        // Input string is empty i.e.., no dominoes are there
        return "";
    }

    // Retrieve the size of dominoes
    int n = dominoes.length();

    // Force array to calculate the net force for each dominoe
    vector<int> force(n, 0);

    // Holds net force at that particular index while traversing
    int netforce = 0;

    // Traverse from left to right and calculate the net force
    // of dominoes that are falling right
    for (int i = 0; i < n; i++) {
        if (dominoes[i] == 'R') {
            // Dominoe is falling Right, the net force will be N
            netforce = n;
        }
        else if (dominoes[i] == 'L') {
            // Dominoe is falling on Left which is not evaluated while
            // traversing from left to right
            netforce = 0;
        }
        else {
            // Dominoe is not pushed yet, need to calculate the force
            // based on the previous dominoe. because the force will be
            // reduced from one dominoe to another, reduce the force by 1
            netforce = max(netforce - 1, 0);
        }

        // Got the netforce for the current dominoe, update the force by
        // adding to the previous force
        force[i] += netforce;
    }

    // Reset the netforce
    netforce = 0;

    // Traverse from Right to left and calculate the net force of dominoes
    // that are falling left
    for (int i = n - 1; i >= 0; i--) {
        if (dominoes[i] == 'L') {
            // Dominoe is falling left, the net force will be N
            netforce = n;
        }
        else if (dominoes[i] == 'R') {
            // Dominoe is falling on Right which is not evaluated while
            // traversing from right to left
            netforce = 0;
        }
        else {
            // Dominoe is not pushed yet, need to calculate the force
            // based on the previous dominoe. because the force will be
            // reduced from one dominoe to another, reduce the force by 1
            netforce = max(netforce - 1, 0);
        }

        // Got the netforce for the current dominoe, update the force by
        // subtracting to the previous force
        force[i] -= netforce;
    }

    // Now that we have the netforce for each dominoe generate the resultant
    // string
    dominoes = "";

    // Traverse each dominoe net force
    for (int f : force) {
        // If the force is negative ie.., the dominoe falls on left, if the
        // netforce is positive, then dominoe falled onto right ant if force
        // is 0, then it is not pushed
        if (f < 0) {
            dominoes += 'L';
        }
        else {
            dominoes += (f > 0 ? 'R' : '.');
        }
    }

    return dominoes;
}
