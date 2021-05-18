
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 968: Binary Tree Cameras
 *
 * Given a binary tree, we install cameras on the nodes of the tree.
 * Each camera at a node can monitor its parent, itself, and its
 * immediate children.
 * Calculate the minimum number of cameras needed to monitor all nodes
 * of the tree.
 *
 * Example 1:
 * Input: [0,0,null,0,0]
 * Output: 1
 * Explanation: One camera is enough to monitor all nodes if placed as shown.
 *
 * Example 2:
 * Input: [0,0,null,0,null,0,null,null,0]
 * Output: 2
 * Explanation: At least two cameras are needed to monitor all nodes of the
 * tree. The above image shows one of the valid configurations of camera
 * placement.
 *
 * Note:
 * The number of nodes in the given tree will be in the range [1, 1000].
 * Every node has value 0.
*/
class Solution {
    /*
     * Approach followed is PostOrder DFS traversal where the traversal
     * goes to leaf nodes and from there checks whether camera is needed
     * or not.
     * Defining 3 enum values which defines the current state of current
     * node
     * . COVERED - This state tells that the node is covered and parent
     *             needs to be covered by itself
     * . HAS_CAMERA - This state tells that the node has camera and its
     *                parent doesn't need any camera
     * . PLEASE_COVER - This state tells that node is requesting the parent
     *                  to install a camera.
     *
     * BaseCase:
     * . If the node is NULL, then it should return "COVERED", then parent
     *   should think about itself for covering.
     *
     */
private:
    typedef enum {
        COVERED = 0,
        PLEASE_COVER,
        HAS_CAMERA,
    } cState;

    int numCameras = 0;

    // Function to perform Post Order DFS and returns the state of camera
    // for the current node
    cState postOrderDfs(TreeNode* root) {
        // Base case check if the node is NULL
        if (root == NULL) {
            // Current NOde is null i.e.., it is covered and parent
            // needs to be covered by itself
            return COVERED;
        }

        // PostOrder L & R root

        // dfs the left node
        cState left = postOrderDfs(root->left);
        // dfs the right node
        cState right = postOrderDfs(root->right);

        if (left == cState::PLEASE_COVER || right == cState::PLEASE_COVER) {
            // Either Left or Right child needs a cover, the current node should
            // install the camera
            numCameras++;

            // return the state HAS_CAMERA
            return cState::HAS_CAMERA;

        }
        else if (left == cState::HAS_CAMERA || right == cState::HAS_CAMERA) {
            // Either left child or right child has camera, then no need to install
            // a camera at this node
            return cState::COVERED;
        }
        // The left and right childs are covered by one of its child cameras and
        // this current node needs a cover
        return cState::PLEASE_COVER;
    }
public:
    int minCameraCover(TreeNode* root) {
        // As traversal is PostOrder,
        // Perform dfs and if the state is PLEASE_COVER, then install camera
        // at the current node
        return postOrderDfs(root) == cState::PLEASE_COVER ? ++numCameras : numCameras;
    }
};
