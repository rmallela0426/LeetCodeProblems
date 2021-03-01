/*
*  Author: Raghavendra Mallela
*/

/*
 * There are 8 prison cells in a row and each cell is either occupied or vacant.
 * Each day, whether the cell is occupied or vacant changes according to the following rules:
 *    . If a cell has two adjacent neighbors that are both occupied or both vacant, then the
 *      cell becomes occupied.
 *    . Otherwise, it becomes vacant.
 * Note that because the prison is a row, the first and the last cells in the row can't have
 * two adjacent neighbors.
 *
 * You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and
 * cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
 *
 * Return the state of the prison after n days (i.e., n such changes described above).
 *
 * Example 1:
 * Input: cells = [0,1,0,1,1,0,0,1], n = 7
 * Output: [0,0,1,1,0,0,0,0]
 * Explanation: The following table summarizes the state of the prison on each day:
 * Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
 * Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
 * Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
 * Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
 * Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
 * Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
 * Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
 * Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
 *
 * Constraints:
 * cells.length == 8
 * cells[i] is either 0 or 1.
 * 1 <= n <= 109
*/
vector<int> prisonAfterNDays(vector<int>& cells, int n) {
    // As per the rule for occupied or vacat, there should a cycle
    // where the sequence repeats, need to find out that. When
    // evaluated with different examples it is seen that sequence is
    // repeated at every 14 days ie.., day 1 repeats at 15th day and
    // so on. Based on this if the first 14 days are there, we can get
    // for any n value.
    // N will be mod of 14
    n = (n % 14 == 0) ? 14 : (n % 14);

    // Loop for the n days
    while (n > 0) {
        // variables to store the prev's and current values
        int prev = 0; // 0th cell is always zero
        int curr = 0;

        // Find the current day sequence and check if the adjacent cells
        // are both occupied or not and update accordingly.
        for (int i = 1; i < 7; i++) {
            // If both neighbour cells are equal in the previous day, then
            // the current cell is occupied on this day.
            curr = cells[i - 1] == cells[i + 1] ? 1 : 0;
            // copy the current day to result to ip
            cells[i - 1] = prev;
            prev = curr;
        }
        // Copy the remaining 2 cells
        cells[6] = prev;
        cells[7] = 0;  // last cell is always empty
        --n;
    }

    return cells;
}
