
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 315: Count Of Smaller Numbers After Self
 *
 * You are given an integer array nums and you have to return a new counts array. The
 * counts array has the property where counts[i] is the number of smaller elements to
 * the right of nums[i].
 *
 * Example 1:
 * Input: nums = [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 * Example 2:
 * Input: nums = [-1]
 * Output: [0]
 *
 * Example 3:
 * Input: nums = [-1,-1]
 * Output: [0,0]
 *
 * Constraints:
 * 1 <= nums.length <= 105
 * -104 <= nums[i] <= 104
*/
/*
 * Approach followed is a Merge Sort technique where the input
 * array is divided and while merging, update the count of no
 * of values less than the current i
 *
 *  Eg:        5, 2, 6, 1
 *                /    \
 *             5, 2    6, 1
 *             /  \    /  \
 *            5   2   6    1
 *
 * while merging, 5 & 2, we see that 2 is right subarray which
 * is smaller and need to put before 5, so we increment the
 * count of 5 as 2 is kept before 5 ie.., The number that needs
 * to be moved from left subarray to right subarray we add the
 * count 1 to left subarry.
*/
#define vv_iter vector<vector<int>>::iterator
void mergesort(vv_iter l, vv_iter r, vector<int>& res) {
    // Base case when l >= r
    if (r - l <= 1) {
        return;
    }

    // Divide the input array into 2 parts
    vv_iter mid = l + (r - l) / 2;

    // Recursively divide the left and right subarrays
    mergesort(l, mid, res);
    mergesort(mid, r, res);

    // Before merging need to calculate the total numbers that are
    // in the right subarray when compared to the value in left
    // subarray
    vv_iter i = l;
    vv_iter j = mid;

    // Loop for all elements in left subarray
    while (i < mid) {
        // Traverse the right subarray only if the element at j is
        // greater than element at i
        // Basically count the number of elements in right subarray
        // that are less than element at i
        while (j < r && (*i)[0] >(*j)[0]) {
            // Number at right subarray is less than that of left
            // subarray. Increment j
            j++;
        }

        // place the num of elements lesser than that of element at i
        res[(*i)[1]] += j - mid;

        i++;
    }

    // Now that we are done with dividing, merge it using std libary
    std::inplace_merge(l, mid, r);
}

vector<int> countSmaller(vector<int>& nums) {
    // Vector to store the result
    vector<int> res(nums.size(), 0);

    // While sorting the indices of the nums will be changed, so
    // inorder to retain the original index, saving the value of
    // the input and the index in an array
    vector<vector<int>> inp;

    // fill the input array with the numbers and index
    for (int i = 0; i < nums.size(); i++) {
        // push the num and index to the array
        inp.push_back(vector<int>{nums[i], i});
    }

    // Call the merge sort
    mergesort(inp.begin(), inp.end(), res);

    return res;
}
