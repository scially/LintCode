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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        string str;
        vector<string> v;
        if(root == nullptr) return v;
        binaryTreePaths(root, v, str);
        return v;
    }
    
    void binaryTreePaths(TreeNode *root, vector<string> &v, string &path){
        string tmp = "->" + to_string(root->val);
        path += tmp;
        if(root->left == nullptr && root->right == nullptr){
            v.push_back(path.substr(2)); //去掉开头的"->"
            path = path.substr(0, path.length()-tmp.length());
            return;
        }
        
        
        if(root->left)  binaryTreePaths(root->left , v, path);
        if(root->right) binaryTreePaths(root->right, v, path);
        path = path.substr(0, path.length()-tmp.length());
    }
};