
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1383: Maximum performanance Of a Team
 *
 * You are given two integers n and k and two integer arrays speed and efficiency both of length n.
 * There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and
 * efficiency of the ith engineer respectively.
 *
 * Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
 *
 * The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency
 * among their engineers.
 * Return the maximum performance of this team. Since the answer can be a huge number, return it modulo
 * 109 + 7.
 *
 * Example 1:
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
 * Output: 60
 * Explanation: 
 * We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4)
 * and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
 *
 * Example 2:
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
 * Output: 68
 * Explanation:
 * This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5
 * to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
 *
 * Example 3:
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
 * Output: 72
 *
 * Constraints:
 * 1 <= <= k <= n <= 105
 * speed.length == n
 * efficiency.length == n
 * 1 <= speed[i] <= 105
 * 1 <= efficiency[i] <= 108
*/
/*
 * Approach is a greedy solution with prority Queue
 *  . Pair both speed and efficiency, sort the pairs in a decreasing order
 *  . Iterate over all the engineers
 *  . Initialize the priority queue as we need to keep always lowers speeds
 *    on the top ie.., with speeds in increasing order. The max size of the
 *    prority queue is k.
 *  . while traversing, if the input size is > k, remove the lowest speed
 *    engineer from the list
 *  . Calculate the max performance of the team in the loop
*/
int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    // vector to store the speed and efficiency of engineers
    vector<pair<int, int>> engineers;

    // push all engineers speed and efficiency into the vector
    for (int i = 0; i < n; i++) {
        // Push the curr idx engineer's speed and efficiency
        engineers.push_back({ efficiency[i], speed[i] });
    }

    // Sort the engineers based on efficiency in a decreasing order
    sort(engineers.begin(), engineers.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    });

    // Initialize the Priority Queue, whose max size is K + 1
    // By default the queue will sort it elements in decreasing order, we need
    // speeds to be increasing order
    auto comp = [](int n1, int n2) { return n1 > n2; };
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);

    // variables to store the sum of all engineers and the performance of team
    long long sumSpeed = 0;
    long long res = 0;

    // Traverse all capabilities of engineers
    for (auto& it : engineers) {
        // Include this engineer in the team
        // Add the engineers speed to the sum of engineers speed in the team
        sumSpeed += it.second;

        // Push the current speed of the engineer to priority queue
        pq.push(it.second);

        // Check if the quueue is full i.e..., it has K elements
        if (pq.size() > k) {
            // Queue size is greater than the max no of engineers that are needed
            // to the team
            // Got an engineer with high speed, remove the lower speed engineer
            sumSpeed -= pq.top();
            pq.pop();
        }

        // calculate the performance of the team
        res = max(res, sumSpeed * it.first);
    }

    // return the performance of the team's by module with 10^9 + 7
    return res % 1000000007;
}
