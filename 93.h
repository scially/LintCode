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
    struct ResultType{
        bool isBalanced;
        int  depth;
        ResultType(bool is, int d): isBalanced(is), depth(d){}
    };
    /*
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        // write your code here
        
        // verson 1
        // ResultType r = help(root);
        // return r.isBalanced;
        
        // verson2
        return maxDepth(root) != -1;
    }
    ResultType help(TreeNode *root){
        if(root == nullptr) return ResultType(true, 0);
        ResultType r = help(root->right);
        ResultType l = help(root->left) ;
        
        if(!r.isBalanced || !l.isBalanced){
            return ResultType(false, -1);
        }
        if(abs(r.depth - l.depth) > 1)
            return ResultType(false, -1);
        
        return ResultType(true, max(l.depth, r.depth) + 1);
    }
    
    int maxDepth(TreeNode *root){
        if(root == nullptr) return 0;
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        
        if(l == -1 || r == -1 || abs(l - r) > 1) return -1;
        else return max(l, r) + 1;
    }
};