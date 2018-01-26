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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        // write your code here
        
        // 非递归
        // if(root == nullptr) return node;
        // TreeNode *prev, *head = root;
        // while(root != nullptr){
        //     prev = root;
        //     if(root->val < node->val) root = root->right;
        //     else root = root->left;
        // }
        
        // if(prev->val < node->val) prev->right = node;
        // else prev->left = node;
        // return head;
        
        // 递归
        if(root == nullptr) return node;
        if(root->val < node->val){
            root->right = insertNode(root->right, node);
            return root;
        }
        else{
            root->left = insertNode(root->left, node);
            return root;
        }
    }
};