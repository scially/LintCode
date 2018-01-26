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
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        // write your code here
        vector<int> v;
        if(root == nullptr) return v;
        stack<TreeNode*> s;
        
        while(true){
            while(root){
                s.push(root);
                root = root->left;
            }
            if(s.empty()) break;
            
            root = s.top(); s.pop();
            if(root->val >= k1 && root->val <= k2)
                v.push_back(root->val);
            
            root = root->right;
        }
        return v;
    }
};