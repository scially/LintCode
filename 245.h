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
     * @param T1: The roots of binary tree T1.
     * @param T2: The roots of binary tree T2.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode * T1, TreeNode * T2) {
        // write your code here
        if(T2 == nullptr) return true;
        if(T1 == nullptr) return false;
        
        if(equal(T1, T2)) return true;
        if(isSubtree(T1->left,  T2)) return true;
        if(isSubtree(T1->right, T2)) return true;
        
        return false;
    }
    bool equal(TreeNode *t1, TreeNode *t2){
        if(t1 == nullptr && t2 == nullptr) return true;
        if(t2 == nullptr) return false;
        if(t1 == nullptr) return false;
        if(t1->val != t2->val) return false;
        
        bool l = equal(t1->left, t2->left);
        bool r = equal(t1->right, t2->right);
        
        return l && r ;
    }
};