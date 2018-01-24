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
     * @param root: the root of tree
     * @return: the max node
     */
    TreeNode * maxNode(TreeNode * root) {
        // write your code here
        return postorder(root);
    }
    
    // 这里为了练习，使用非递归版后序遍历
    TreeNode *postorder(TreeNode *root){
       TreeNode *maxNode = root;
       stack<TreeNode*> s;
       TreeNode *lastView = nullptr;
       while(root != nullptr){
           s.push(root);
           root = root->left;
       }
       while(!s.empty()){
            root = s.top();
            s.pop();
           if(root->right == nullptr || root->right == lastView){
               lastView = root;
               maxNode = maxNode->val > root->val ? maxNode : root;
           }
           else{
               s.push(root);
               root = root->right;
               while(root != nullptr){
                   s.push(root);
                   root = root->left;
               }
           }
       }
       return maxNode;
    }
};