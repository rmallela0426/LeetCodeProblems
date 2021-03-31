
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 870: Advantage Shuffle
 *
 * Given two arrays A and B of equal size, the advantage of A with respect to B
 * is the number of indices i for which A[i] > B[i].
 * Return any permutation of A that maximizes its advantage with respect to B.
 *
 * Example 1:
 * Input: A = [2,7,11,15], B = [1,10,4,11]
 * Output: [2,11,7,15]
 *
 * Example 2:
 * Input: A = [12,24,8,32], B = [13,25,32,11]
 * Output: [24,32,8,12]
 *
 * Note:
 * 1 <= A.length = B.length <= 10000
 * 0 <= A[i] <= 10^9
 * 0 <= B[i] <= 10^9
*/
/*
 * Solution is to find the maximum permuted array A for which A[i] > B[i] for each i
 * i.e.., Shuffle the array A such that there will be maximum elements in result,
 * that satisfies condition A[i] > B[i]
 *
 * Pseudo code:
 * 1. Sort the arrary A
 * 2. Loop for every element in B and start with maximum element in a
 * 3. If B[i] < A[last], then insert the least max element in A into result
 * 4. If B[i] >= A[last], then insert the smallest element(0th element) into result
*/
int getLeastMaxElement(vector<int>& A, int target) {
    if (A.size() == 1) {
        // If there is only one element in array, then least max element will
        // be same element
        return 0;
    }
    // Loop until the largest smallest number of target is found
    // Skip the last element as it is already checked
    for (int idx = A.size() - 2; idx >= 0; idx--) {
        if (A[idx] <= target) {
            // Found the largest smallest number, return the index
            // of least max element.
            return idx + 1;
        }
    }
    return 0;
}

vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    vector<int> res;

    // Sort the element in array A
    std::sort(A.begin(), A.end());

    // Loop all elements in array B
    for (int elem : B) {
        // B[i] < A[last], then insert the least max element in A into result
        // B[i] >= A[last], then insert the smallest element(0th element) into result
        int idx = A.back() > elem ? getLeastMaxElement(A, elem) : 0;
        res.push_back(A[idx]);
        // Remove the inserted element from array
        A.erase(A.begin() + idx);
    }

    return res;
}
