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
     * @param A: an integer array
     * @return: A tree node
     */
    TreeNode * sortedArrayToBST(vector<int> &A) {
        // write your code here
        //return sortedArrayToBST(A, 0, A.size());
    
        return sortedArrayToBST(A, 0, A.size()-1);
    }
    
    // leetcode可以通过
    // TreeNode *sortedArrayToBST(vector<int> &A, int l, int r){
    //     if(l >= r ) return nullptr;
    //     int mid = l + (r-l)/2;
    //     TreeNode *root = new TreeNode(A[mid]);
    //     root->left = sortedArrayToBST(A, l, mid);
    //     root->right= sortedArrayToBST(A, mid+1, r);
    //     return root;
    // }
    
      TreeNode *sortedArrayToBST(vector<int> &A, int l, int r){
        if(l > r ) return nullptr;
        int mid = l + (r-l)/2;
        TreeNode *root = new TreeNode(A[mid]);
        root->left = sortedArrayToBST(A, l, mid-1);
        root->right= sortedArrayToBST(A, mid+1, r);
        return root;
    }
};