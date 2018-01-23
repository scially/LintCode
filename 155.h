/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if(root == nullptr) return 0;
        return minDepth(root, 0);
    }
    int minDepth(TreeNode *root, int depth){
        int d1 = INT_MAX, d2 = INT_MAX;
        if(root->left == nullptr && root->right == nullptr) 
            return depth+1;
        if(root->left)
            d1 = minDepth(root->left, depth+1);
        if(root->right)
            d2 = minDepth(root->right, depth+1);
        return min(d1, d2);
    }
};