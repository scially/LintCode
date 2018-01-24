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
     * @param a: the root of binary tree a.
     * @param b: the root of binary tree b.
     * @return: true if they are identical, or false.
     */
    bool isIdentical(TreeNode * a, TreeNode * b) {
        // write your code here
        if(a == nullptr && b != nullptr) return false;
        if(b == nullptr && a != nullptr) return false;
        if(a == nullptr && b == nullptr) return true;
        if(a->val != b->val) return false;
        bool b1 = isIdentical(a->left, b->left);
        bool b2 = isIdentical(a->right, b->right);
        return b1 && b2;
    }
};