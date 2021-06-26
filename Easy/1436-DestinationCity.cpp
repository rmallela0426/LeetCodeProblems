
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1436: Destination City
 *
 * You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct
 * path going from cityAi to cityBi. Return the destination city, that is, the city without any
 * path outgoing to another city.
 * It is guaranteed that the graph of paths forms a line without any loop, therefore, there will
 * be exactly one destination city.
 *
 * Example 1:
 * Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
 * Output: "Sao Paulo"
 * Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination
 * city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
 *
 * Example 2:
 * Input: paths = [["B","C"],["D","B"],["C","A"]]
 * Output: "A"
 * Explanation: All possible trips are:
 *      "D" -> "B" -> "C" -> "A".
 *      "B" -> "C" -> "A".
 *      "C" -> "A".
 *      "A".
 * Clearly the destination city is "A".
 *
 * Example 3:
 * Input: paths = [["A","Z"]]
 * Output: "Z"
 *
 * Constraints:
 * 1 <= paths.length <= 100
 * paths[i].length == 2
 * 1 <= cityAi.length, cityBi.length <= 10
 * cityAi != cityBi
 * All strings consist of lowercase and uppercase English letters and the space character.
*/
string destCity(vector<vector<string>>& paths) {
    /*
     * Approach is to save the starting cities in a Set and traverse
     * paths in input and search if the destination city is present
     * in the set or not if not, then it will be the unique city
     *
    */
    // Base case if paths are empty
    if (paths.empty()) {
        // No paths returning null
        return "";
    }

    // map to store the paths
    std::unordered_set<string> mp;

    // put all the paths in map
    for (vector<string>& path : paths) {
        // push it to map
        mp.insert(path[0]);
    }

    // Traverse the all the paths input paths
    for (vector<string>& path : paths) {
        // search the destination city in the map
        if (mp.count(path[1]) == 0) {
            // the destination city is not available
            return path[1];
        }
    }

    // There is no destination city that is not going to any other city
    return "";
}
