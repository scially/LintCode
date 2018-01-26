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
        int singlepath; //某个节点左右两个子树最大的路径，不包括root节点
        int maxpath;
        ResultType(int s, int m): singlepath(s), maxpath(m){}
    };
    
    int maxPathSum(TreeNode * root) {
        // write your code here
       ResultType r = any2Any(root);
       return r.maxpath;
    }
    
    ResultType any2Any(TreeNode *root){
        if(root == nullptr) return ResultType(0, INT_MIN);
        
        ResultType l = any2Any(root->left) ;
        ResultType r = any2Any(root->right);
        
        // root2Any
        // 对于这一行代码来说，求的是从root到任一节点最大的路径
        // 当某个节点值为负时，我们从这儿断开，存为0，这样当回到父节点时，最大值就是父节点
        int singlepath = max(max(l.singlepath, r.singlepath) + root->val, 0);
        int maxpath = max(l.singlepath + r.singlepath + root->val, 
                          max(l.maxpath, r.maxpath));
    
        return ResultType(singlepath, maxpath);
    }
};