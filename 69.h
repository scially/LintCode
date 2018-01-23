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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        // 只用一个队列, 也就是BFS
        // vector<vector<int>> v;
        // vector<int> r;
        // if(root == nullptr) return v;
        // queue<TreeNode*> q;
        // q.push(root);
        // TreeNode *lastView = root;
        // while(!q.empty()){
        //     root = q.front();
        //     q.pop();
        //     r.push_back(root->val);
            
        //     if(root->left) q.push(root->left);
        //     if(root->right)q.push(root->right);
        //     if(root == lastView){
        //         v.push_back(r);
        //         r.clear();
        //         lastView = q.back();
        //     }
        // }
        
        // return v;
        
        // DFS， 也就是递归来做
        vector<vector<int>> v;
        if(root == nullptr) return v;
        levelOrder(root, 0, v);
        return v;
    }
    
    void levelOrder(TreeNode *root, int lev, vector<vector<int>> &v){
        if(root == nullptr) return;
        if(lev < v.size()){
            v[lev].push_back(root->val);
        }
        else{ 
            vector<int> r;
            r.push_back(root->val);
            v.push_back(r);
        }
        
        levelOrder(root->left, lev+1, v);
        levelOrder(root->right, lev+1, v);
    }
};