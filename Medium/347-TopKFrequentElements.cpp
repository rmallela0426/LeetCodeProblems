
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 347: Top K Frequent Elements
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 * Constraints:
 * 1 <= nums.length <= 105
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
*/
/*
 * Solution is to find the k most frequent elements in the array
 * In order to find that we follow
 *   . Find the frequency of each element and store it in map
 *   . Sort the map based on frequency
 *   . Get the top k elements from map and return
 * The time complexity of the above solution is
 *      O(N) + O(NlogN) + O(K) = O(NlogN)
 * But the solution needs a complexity of < O(NlogN)
 * In order to improve our solution, sorting should be reduced and
 * and can be replaced by priority Queue where sorting based on
 * frequency can be done during push itself.
 *
 *   . Find the frequency - O(N)
 *   . Push the k elements onto HEAP which takes O(logK) and then
 *     do push and pop remaining (N-K) elements based on the frequency
 *     which takes O((N -K)logK)  => O(NlogK)
 *   . Build the output array from the prority Queue - O(klogK)
 * Overall complexity is O(NlogK), space complexity - O(N+K)
*/
vector<int> topKFrequent(vector<int>& nums, int k) {
    // map to store the frequency of each element
    std::map<int, int> mp;

    for (int num : nums) {
        // Calculate the frequencies
        mp[num]++;
    }

    // lambda function to sort the input based on the frequencies
    auto cmp = [&mp](int n1, int n2) {
        // Logic is such that the element with min frequency is at top
        return mp[n1] > mp[n2];
    };

    // Build a priority Queue which will be of size K elements and the
    // element with less freq will be on top. Once the K elements are
    // inserted, and if a new element with high fequency tries to add
    // into queue by removing element with low frequency which is on
    // top
    std::priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    // Build the Prority Queue
    for (auto num : mp) {
        // Push the first K elements to queue
        pq.push(num.first);

        if (pq.size() > k) {
            // Now Queue is full try to remove the min frequency element
            // ie.., top element
            pq.pop();
        }
    }

    // Build a resultant vector of K frequent elements
    vector<int> res(k);
    for (int i = 0; i < k; i++) {
        res[i] = pq.top();
        pq.pop();
    }

    return res;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    if (nums.size() == k) {
        // There are only k elements in array, return those
        return nums;
    }

    // map to store the frequency of each element
    std::map<int, int> mp;

    for (int num : nums) {
        // Calculate the frequencies
        mp[num]++;
    }

    // lambda function to sort the input based on the frequencies
    auto cmp = [&](auto& n1, auto& n2) {
        // Logic is such that the element with min frequency is at top
        return n1.first > n2.first;
    };

    // Build a priority queue and push the elements in the queue with
    // frequency and value such that the queue will be sorted based on
    // frequency.
    std::priority_queue<pair<int, int>> pq;

    // Build the Prority Queue
    for (auto num : mp) {
        pq.push({ num.second, num.first });
    }

    // Build a resultant vector of K frequent elements
    vector<int> res(k);
    for (int i = 0; i < k; i++) {
        res[i] = pq.top().second;
        pq.pop();
    }

    return res;
}
