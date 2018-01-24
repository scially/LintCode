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
     * @return: 
     */
    void flatten(TreeNode * root) {
        // write your code here
        if(root == nullptr) return;
        
        if(root->left != nullptr){
            TreeNode *node = rightnode(root->left);

            node->right = root->right;

            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
        flatten(root);
    }
    TreeNode* rightnode(TreeNode *root){
        while(root->right != nullptr)
            root = root->right;
        return root;
    }
    
    // debug 
    void preorder(TreeNode *root){
        stack<TreeNode*> s;
        while(true){
            while(root != nullptr){
                cout << root->val << endl;
                s.push(root);
                root = root->left;
            }
            if(s.empty()) break;
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
};