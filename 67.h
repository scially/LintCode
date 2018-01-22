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
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here
        
        // 迭代版
        // vector<int> v;
        // inorderTraversrsal(root, v);
        // return v;
        
        // 递归版
        vector<int> v;
        stack<TreeNode*> s;
        if(root == nullptr) return v;
        while(true){
            while(root != nullptr){
                s.push(root);
                root = root->left;
            }
            if(s.empty()) break;
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
    }
    void inorderTraversrsal(TreeNode *root, vector<int> &v){
        if(root == nullptr) return;
        inorderTraversrsal(root->left, v);
        v.push_back(root->val);
        inorderTraversrsal(root->right, v);
    }
};