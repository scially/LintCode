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
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        // write your code here
        vector<vector<int>> v;
        if(root == nullptr) return v;
        vector<int> r;
        find(root, r, v, target);
        return v;
    }
    
    void find(TreeNode *root, vector<int> &r, vector<vector<int>> &v, int target){
        // 到叶子节点会出现重复递归
        // if(root == nullptr && target != 0){
        //     return;
        // }
        // if(root == nullptr && target == 0){
        //     v.push_back(r);
        //     return;
        // }
        r.push_back(root->val);
        
        if(root->left == nullptr && root->right == nullptr){ // 叶子节点
            if(target == root->val){
                v.push_back(r);
                //
                r.pop_back();
                return;
            }
        }
        
        if(root->left)  find(root->left,  r, v, target - root->val);
        if(root->right) find(root->right, r, v, target - root->val);
        r.pop_back();
    }
};