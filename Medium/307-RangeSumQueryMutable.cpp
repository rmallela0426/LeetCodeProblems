
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 307: Range Sum Query - Mutable
 *
 * Given an integer array nums, handle multiple queries of the following types:
 *  . Update the value of an element in nums.
 *  . Calculate the sum of the elements of nums between indices left and right inclusive
 *    where left <= right.
 *
 * Implement the NumArray class:
 * . NumArray(int[] nums) Initializes the object with the integer array nums.
 * . void update(int index, int val) Updates the value of nums[index] to be val.
 * . int sumRange(int left, int right) Returns the sum of the elements of nums between indices
 *   left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 *
 * Example 1:
 * Input
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * Output
 * [null, 9, null, 8]
 *
 * Explanation
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
 * numArray.update(1, 2);   // nums = [1, 2, 5]
 * numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 *
 * Constraints:
 * 1 <= nums.length <= 3 * 104
 * -100 <= nums[i] <= 100
 * 0 <= index < nums.length
 * -100 <= val <= 100
 * 0 <= left <= right < nums.length
 * At most 3 * 104 calls will be made to update and sumRange.
*/
class NumArray {
    /*
     * Approach followed is Segment tree in which the parent node will
     * save store current sum of its child nodes except the leaf node
     * which will store the current values as the leaf nodes doesn't
     * have children. Each node will have the start and end indices of
     * the children that sum it holds.
    */
    struct SegmentNode {
        // Node that holds the start and end
        int start;
        int end;
        // Variable to store the sum
        int sum;
        // Variables to store the children
        SegmentNode* left;
        SegmentNode* right;

    public:
        // Constructor
        SegmentNode(int s, int e) {
            start = s;
            end = e;
            sum = 0;
            left = NULL;
            right = NULL;
        }
    };

    // variable that stores the root of the tree
    SegmentNode* root;

    SegmentNode* buildTree(vector<int>& nums, int start, int end) {
        // Boundary case where we are done with all elements
        if (start > end) {
            return NULL;
        }

        // Create a new node
        SegmentNode* node = new SegmentNode(start, end);

        // Check if the node is a leaf node ie.., start and end are equal
        if (start == end) {
            // Leaf node, the sum will be the value at that index
            node->sum = nums[start];
        }
        else {
            // Create a segment tree using a BS algorithm
            int mid = start + (end - start) / 2;

            // Generate the left subtree
            node->left = buildTree(nums, start, mid);
            // Generate the right subtree
            node->right = buildTree(nums, mid + 1, end);

            // Current node sum should be equal to sum of left subtree and right subtree
            node->sum = node->left->sum + node->right->sum;
        }

        return node;
    }

    void update(SegmentNode* root, int idx, int val) {
        // Base case if we reach a leaf node
        if (root->start == root->end) {
            // Update the at the leaf node
            root->sum = val;

            return;
        }

        // Do a Binary search
        int mid = root->start + (root->end - root->start) / 2;

        // Check if updated idx is on the left subtree or on the right subtree
        // If the index is <= mid then value to be updated will be on left tree
        // else it will be on right tree
        update(idx <= mid ? root->left : root->right, idx, val);

        // There is a change in values either in left or right subtree, update
        // the current sum
        root->sum = root->left->sum + root->right->sum;

        return;
    }

    int sumRange(SegmentNode* node, int start, int end) {
        if (node == NULL) {
            return 0;
        }
        // Base case where start end range matches with current nodes
        // start and end
        if (node->start == start && node->end == end) {
            // Current node sum is needed
            return node->sum;
        }

        // Do a binary search on the range and find it out whether the required sum
        // is in the left subtree or right subtree or in both the trees
        int mid = node->start + (node->end - node->start) / 2;

        // If the end <= mid ie.., we need to parse on to the left subtree
        if (end <= mid) {
            return sumRange(node->left, start, end);
        }

        // If the start >= mid + 1 ie.., we need to parse on the right subtree
        if (start >= mid + 1) {
            return sumRange(node->right, start, end);
        }

        // The range is in both the subtrees
        return sumRange(node->left, start, mid) + sumRange(node->right, mid + 1, end);
    }

public:

    NumArray(vector<int>& nums) {
        // Create a Segment Tree
        root = buildTree(nums, 0, nums.size() - 1);
    }

    void update(int index, int val) {
        return update(root, index, val);
    }

    int sumRange(int left, int right) {
        return sumRange(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
