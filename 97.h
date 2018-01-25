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
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        // verson 1
        //return maxDepth(root, 0);
        
        // verson 2
        if(root == nullptr) return 0;
        int d1 = maxDepth(root->left);
        int d2 = maxDepth(root->right);
        return max(d1, d2) + 1;
    }
    
    int maxDepth(TreeNode *root, int depth){
        if(root == nullptr) return depth;
        int d1 = maxDepth(root->left, depth+1);
        int d2 = maxDepth(root->right, depth+1);
        return max(d1, d2);
    }
    
};