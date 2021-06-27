
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 684: Redundant Connection
 *
 * In this problem, a tree is an undirected graph that is connected and has no cycles.
 * You are given a graph that started as a tree with n nodes labeled from 1 to n, with
 * one additional edge added. The added edge has two different vertices chosen from 1
 * to n, and was not an edge that already existed. The graph is represented as an array
 * edges of length n where edges[i] = [ai, bi] indicates that there is an edge between
 * nodes ai and bi in the graph.
 *
 * Return an edge that can be removed so that the resulting graph is a tree of n nodes.
 * If there are multiple answers, return the answer that occurs last in the input.
 *
 * Example 1:
 *    1 -> 2
 *    |    /
 *      3
 *
 * Input: edges = [[1,2],[1,3],[2,3]]
 * Output: [2,3]
 *
 * Example 2:
 * Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
 * Output: [1,4]
 *
 * Constraints:
 * . n == edges.length
 * . 3 <= n <= 1000
 * . edges[i].length == 2
 * . 1 <= ai < bi <= edges.length
 * . ai != bi
 * . There are no repeated edges.
 * . The given graph is connected.
*/
/*
 * Approach followed is Union find with Rank technique, where the
 * union of the nodes are taken. If a new node needs to added, then
 * for making the decision which one is parent and which one is child
 * is based on the Rank for that node.
 * A Rank with the highest node is parent and rank with lowest node
 * is child
 *
 * Steps:
 *  . Initialize a Parent vector to store the current nodes and parents
 *  . Initialize a Rank vector which stores the rank of each node for
 *    detecting whether the node can be a parent or child
 *  . Traverse all the edges, perform the union for this edge, if the
 *    parents, grand parents etc.., are equal for these nodes in edge
 *    then there will be a loop. By removing this graph is a tree now.
*/

int find(int n, vector<int>& parent) {
    if (parent[n] == -1)
        return n;
    return parent[n] = find(parent[n], parent);
}

bool unione(int u, int v, vector<int>& parent, vector<int>& rank) {
    // Retrieve the parents for both u and v edges
    int pu = find(u, parent);
    int pv = find(v, parent);

    // Check if both have any parent or grantparent.....
    if (pu == pv) {
        // Both the nodes have a parent in common, we shouldn't connect
        // this edge
        return false;
    }

    // These nodes doesn't have a parent in common, the edges can be
    // connected based on the rank of each node.
    if (rank[pu] > rank[pv]) {
        // Rank of pu is greater than pv, pu wil be the parent of pv
        rank[pu] += rank[pv];
        // copy the parent to pv
        parent[pv] = pu;
    }
    else {
        // Rank of pv is greater or equal to pu, then pv will be parent
        // of pu
        rank[pv] += rank[pu];
        parent[pu] = pv;
    }

    return true;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    // Initialize n, the size of the edges
    int n = edges.size();

    // Initialize a parent vector that stores the parents of each node
    // size is +1 for storing the 0th node also for easy accessing.
    vector<int> parent(n + 1, -1);

    // Initialize a rank vector to store the current rank for the node
    // At beginning the rank of each node is 1 ie.., disjoint
    vector<int> rank(n + 1, 1);

    // vector to store the res
    vector<int> res;

    // Traverse the input edges
    for (vector<int>& edge : edges) {
        // Check the union, which will return the false if one of the parents
        // of these nodes are equal
        if (!unione(edge[0], edge[1], parent, rank)) {
            // Both nodes share the same parent ie.., this edge forms a
            // loop, remove that to make true
            res = edge;
        }
    }

    return res;
}
