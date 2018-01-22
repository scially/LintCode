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
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        // 递归版
        // vector<int> v;
        // preorderTraversal(root, v);
        // return v;
        
        // 迭代版
        vector<int> v;
        if(root == nullptr) return v;
        
        stack<TreeNode*> s;
        while(true){
            while(root){
                v.push_back(root->val);
                s.push(root->right);
                root = root->left;
            }
            if(s.empty()) break;
            root = s.top();
            s.pop();
        }
       return v;
    }
    
    void preorderTraversal(TreeNode * root, vector<int> &v) {
        // write your code here
        if(root == nullptr) return;
        v.push_back(root->val);
        preorderTraversal(root->left, v);
        preorderTraversal(root->right, v);
    }
};