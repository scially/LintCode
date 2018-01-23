
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
     * @param root: A tree
     * @return: buttom-up level order a list of lists of integer
     */
    vector<vector<int>> levelOrderBottom(TreeNode * root) {
        // write your code here
        vector<vector<int>> v;
        vector<int> r;
        if(root == nullptr) return v;
        TreeNode *lastView = root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root = q.front();
            r.push_back(root->val);
            q.pop();
            if(root->left) q.push(root->left);
            if(root->right)q.push(root->right);
            if(root == lastView){
                lastView = q.back();
                v.insert(v.begin(), r);
                r.clear();
            }
        }
        return v;
    }
};