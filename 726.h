class Solution {
public:
    /*
     * @param : the given tree
     * @return: Whether it is a full tree
     */
    bool isFullTree(TreeNode * root) {
        // write your code here
        if(root == nullptr) return true;
        if(root->left == nullptr && root->right == nullptr) return true;
        if(root->right == nullptr || root->left == nullptr) return false;
        
        bool l = isFullTree(root->left);
        bool r = isFullTree(root->right);
        return l && r;
    }
};