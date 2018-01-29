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
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        // write your code here
        vector<int> data;
        vector<vector<int>> datas;
        queue<TreeNode*> q;
        if(root == nullptr) return datas;
        // 层序遍历
        rightNode = root;
        q.push(root);
        while(!q.empty()){
            root = q.front(); q.pop();
            data.push_back(root->val);
            if(rightNode == root){
                
                datas.push_back(data);
                data.clear();

                rightNode = root->right ? root->right : root->left;
                // 
                if(rightNode == nullptr){
                    rightNode = q.back();
                }
                
            }
            //rightNode = root->right ? root->right : root->left;
            if(root->left)  q.push(root->left);
            if(root->right) q.push(root->right);
        }
        zigzag(datas);
        return datas;
    }
private:
    TreeNode *rightNode = nullptr;
    void zigzag(vector<vector<int>> &datas){
        for(int i = 0; i < datas.size(); i++){
            if(i % 2 != 0)
                reverse(datas[i].begin(), datas[i].end());
        }
    }
};