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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    struct ResultType{
        int root2any; //某个节点左右两个子树最大的路径，不包括root节点
        int any2any;
        ResultType(int s, int m): root2any(s), any2any(m){}
    };
    
    int maxPathSum(TreeNode * root) {
        // write your code here
       ResultType r = any2Any(root);
       return r.any2any;
    }
    
    ResultType any2Any(TreeNode *root){
        if(root == nullptr) return ResultType(INT_MIN, INT_MIN);
        
        ResultType l = any2Any(root->left) ;
        ResultType r = any2Any(root->right);
        
        int root2any = max(max(l.root2any, r.root2any),0 ) + root->val;
        int any2any = max(max(l.any2any, r.any2any),  //左右子树分别的最大路径
                          max(l.root2any, 0) + max(r.root2any, 0) + root->val);
    
        return ResultType(root2any, any2any);
    }
};