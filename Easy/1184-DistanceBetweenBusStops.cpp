
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1184: Distance Between Bus Stops
 *
 * A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance
 * between all pairs of neighboring stops where distance[i] is the distance between the
 * stops number i and (i + 1) % n.
 *
 * The bus goes along both directions i.e. clockwise and counterclockwise.
 * Return the shortest distance between the given start and destination stops.
 *
 * Example 1:
 *                 1
 *          0 -------------- 1
 *          |                |
 *        4 |                | 2
 *          |                |
 *          3 ---------------2
 *                 3
 *
 * Input: distance = [1,2,3,4], start = 0, destination = 1
 * Output: 1
 * Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.
 *
 * Example 2:
 * Input: distance = [1,2,3,4], start = 0, destination = 2
 * Output: 3
 * Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.
 *
 * Example 3:
 * Input: distance = [1,2,3,4], start = 0, destination = 3
 * Output: 4
 * Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.
 *
 * Constraints:
 * 1 <= n <= 10^4
 * distance.length == n
 * 0 <= start, destination < n
 * 0 <= distance[i] <= 10^4
*/
/*
 * Approach followed is a greedy approach where we calculate the total
 * distance between bustops when the bus moves in clock wise direction.
 * Now calculate the total distance between bustops when the bus moves
 * in anti clock wise direction. In order to calculate this we can just
 * calculate the total distance of the input vector minus the distance
 * travelled by bus in clock wise from start to destination.
*/
int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    // Base Case: where distance vector is empty or start and destination
    // are zero
    if (distance.empty() || (start == 0 && destination == 0)) {
        return 0;
    }

    // size of the input vector
    int n = distance.size();

    // storing min Distance
    int minDistance = INT_MAX;

    // total distance from start to destination
    int tdistance = 0;

    // Case when the bus moves in Clock Wise direction
    // Loop from start to destination and get the total distance
    while (start != destination) {
        // Add the distance
        tdistance += distance[start];

        start = (start + 1) % n;
    }

    // Get the min distance when the bus moves in clock wise direction
    minDistance = min(tdistance, minDistance);

    // Case when the bus moves Anti Clock Wise direction
    // Calculate the total distance of the bus from 0th idx to 0th idx
    // and subtract the distance from start to destination when bus moves
    // in clock wise will give the distance when moves in AntiClockwise
    // direction
    tdistance = accumulate(distance.begin(), distance.end(), 0) - tdistance;

    // Return the min distance required for the bus to trave from start
    // to destination
    return min(minDistance, tdistance);
}
