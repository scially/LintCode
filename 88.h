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
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B){
        // write your code here
        if(root == nullptr) return nullptr;
        if(root == A) return A;
        if(root == B) return B;
        TreeNode *l = lowestCommonAncestor(root->left, A, B);
        TreeNode *r = lowestCommonAncestor(root->right,A, B);
        
        if(l != nullptr && r != nullptr) return root;
        if(l != nullptr) return l;
        if(r != nullptr) return r;
        return nullptr;
    }
};