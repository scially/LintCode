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
     * @return: root of new tree
     */
    TreeNode * cloneTree(TreeNode * root) {
        // write your code here
        if(root == nullptr) return nullptr;
        TreeNode *node = new TreeNode(root->val);
        node->left = cloneTree(root->left);
        node->right = cloneTree(root->right);
        return node;
    }
    
    
};