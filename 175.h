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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode * root) {
        // write your code here
        
        // 递归版
        // if(root == nullptr) return;
        // TreeNode *rightNode = root->right;
        // root->right = root->left;
        // root->left = rightNode;
        // invertBinaryTree(root->left);
        // invertBinaryTree(root->right);
        
        // 非递归版
        if(root == nullptr) return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            root = s.top();
            s.pop();
            TreeNode *l = root->left, *r = root->right;
            root->left = r;
            root->right = l;
            if(l) s.push(l);
            if(r) s.push(r);
        }
    }
};