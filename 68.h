
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
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        // write your code here
        
        // 递归版
        // vector<int> v;
        // postorderTraversal(root, v);
        // return v;
        
        // 迭代版
        vector<int>  v;
        stack<TreeNode*> s;
        TreeNode* cur = root, *lastView = nullptr;
        while(cur != nullptr){
            s.push(cur);
            cur = cur->left;
        }
        while(!s.empty()){
            // 循环一开始，此时cur是最左子树节点
            cur = s.top();
            s.pop();
            // 根节点要被访问无非两种情况
            // 1. 右子数为NULL
            // 2. 右子数被访问过了
            if(cur->right == nullptr || cur->right == lastView){
                v.push_back(cur->val);
                lastView = cur;
            }
            else{
                // 此时 cur->right 一定不为NULL
                s.push(cur);
                cur = cur->right;
                while(cur){
                    s.push(cur);
                    cur = cur->left;
                }
            }
        }
        return v;
    }
    
    void postorderTraversal(TreeNode *root, vector<int> &v){
        if(root == nullptr) return;
        postorderTraversal(root->left, v);
        postorderTraversal(root->right, v);
        v.push_back(root->val);
    }
};