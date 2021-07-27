
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 690: Employee Importance
 *
 * You have a data structure of employee information, which includes the employee's
 * unique id, their importance value, and their direct subordinates' id.
 *
 * You are given an array of employees employees where:
 * . employees[i].id is the ID of the ith employee.
 * . employees[i].importance is the importance value of the ith employee.
 * . employees[i].subordinates is a list of the IDs of the subordinates of the ith
 *   employee.
 * Given an integer id that represents the ID of an employee, return the total importance
 * value of this employee and all their subordinates.
 *
 * Example 1:
 *               1 id, 5 importance
 *            /     \
 *    id     2       3
 * importce  3       3
 *
 * Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
 * Output: 11
 * Explanation: Employee 1 has importance value 5, and he has two direct subordinates:
 * employee 2 and employee 3.
 * They both have importance value 3.
 * So the total importance value of employee 1 is 5 + 3 + 3 = 11.
 *
 * Example 2:
 * Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
 * Output: -3
 *
 * Constraints:
 * 1 <= employees.length <= 2000
 * 1 <= employees[i].id <= 2000
 * All employees[i].id are unique.
 * -100 <= employees[i].importance <= 100
 * One employee has at most one direct leader and may have several subordinates.
 * id is guaranteed to be a valid employee id.
*/
/* Approach followed is a DFS Solution */
int getImportance(vector<Employee*> employees, int id) {
    // Index for employee details who has the required id
    int index = -1;

    // Traverse the loop and find the Employee details corresponding
    // to the id
    for (int idx = 0; idx < employees.size(); idx++) {
        // Check whether this employee is what is required
        if (employees[idx]->id == id) {
            // This employees details is what is needed
            index = idx;
            break;
        }
    }

    // Check if the details of the employee that is needed is present
    // in input or not
    if (index == -1) {
        // No such employee with id is not present
        return 0;
    }

    // Total Importance of his and his subordinates
    int totalimp = employees[index]->importance;

    // Check if there are subordinates for this employee
    if (employees[index]->subordinates.empty()) {
        // No subordinates for this employee
        return totalimp;
    }

    for (int& subOrdId : employees[index]->subordinates) {
        // DFS to search the subordinate id and return his importance
        totalimp += getImportance(employees, subOrdId);
    }

    // Return total importance
    return totalimp;
}
