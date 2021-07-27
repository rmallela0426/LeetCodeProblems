
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 295: Find Median From Datastream
 *
 * The median is the middle value in an ordered integer list. If the size of the list
 * is even, there is no middle value and the median is the mean of the two middle values.
 *
 * For example, for arr = [2,3,4], the median is 3.
 * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
 *
 * Implement the MedianFinder class:
 * . MedianFinder() initializes the MedianFinder object.
 * . void addNum(int num) adds the integer num from the data stream to the data structure.
 * . double findMedian() returns the median of all elements so far. Answers within 10-5 of
 *   the actual answer will be accepted.
 *
 * Example 1:
 * Input:
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * Output:
 * [null, null, null, 1.5, null, 2.0]
 *
 * Explanation:
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 * Constraints:
 * -105 <= num <= 105
 * There will be at least one element in the data structure before calling findMedian.
 * At most 5 * 104 calls will be made to addNum and findMedian.
 *
 * Follow up:
 * . If all integer numbers from the stream are in the range [0, 100], how would you optimize
 *   your solution?
 * . If 99% of all integer numbers from the stream are in the range [0, 100], how would you
 *   optimize your solution?
*/
class MedianFinder {
private:
    /*
     * Approach followed is a greedy where a vector is used to store
     * the nums and is sorted using a binary search in ascending
     * order. When the median query is called then based on whether
     * the input size is even or odd the median is calculated.
    */
    // Input vector to store, the input nums
    vector<int> nums;

    // Binary Search to find the position of the number to be added
    // to the input vector.
    // Below function returns the index where the number needs to be
    // added
    int bs(int& num, int left, int right) {
        // BaseCase: If the left is greater than right
        if (left > right) {
            // left index is greater than right ie.., we surprassed the
            // elements or the vector is empty
            return left;
        }

        // Check if the left and right index are same
        if (left == right) {
            // Both indices are pointing to same element, need to check
            // whether the number to be added is greater than number at
            // left index, then it should be left + 1 else insert it at
            // left.
            return num > nums[left] ? left + 1 : left;
        }

        // As the input vetor is sorted, find the middle position of
        // vector based on left and right
        int mid = left + (right - left) / 2;

        // Check if number to be added is same as middle number
        if (nums[mid] == num) {
            // Number to be added is same as number at the mid index,
            // need to add at mid + 1
            return mid + 1;
        }

        // check the number to be added is greater than number at mid index
        if (num > nums[mid]) {
            // number to be added is greater than number at mid, need to
            // search on the right subarray
            // Update the mid index based on whether mid is equal to right
            return bs(num, mid != right ? mid + 1 : mid, right);
        }

        // Number to be added is less than element at mid, need to search on
        // left subarray.
        // Update the end index based on whether left is equal to mid
        return bs(num, left, left != mid ? mid - 1 : mid);
    }

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        // Try to find the exact position where to insert the num in sorted
        // array using binary search
        int idx = bs(num, 0, nums.size() - 1);

        // Insert the element at the index found using binary search
        nums.insert(nums.begin() + idx, num);
    }

    double findMedian() {
        // Retrieve the index of middle element
        int idx = nums.size() / 2;

        // Check if the size is even or odd
        if (nums.size() % 2 == 0) {
            // vector size is even, the median is the average of
            // middle 2 nos
            // Retrieve the average of the middle 2 numbers
            return (float)((nums[idx] + nums[idx - 1])) / 2;
        }
        else {
            // the input size is odd, median is the middle number
            return nums[idx];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
