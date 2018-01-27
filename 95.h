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
private:
    TreeNode *prev = nullptr;

    struct ResultType{
        TreeNode *maxNode, *minNode;
        bool isBST;
        ResultType(TreeNode *n1, TreeNode *n2, bool i):
            maxNode(n1), minNode(n2), isBST(i){}
    };
public:
    /*
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root){
        
        // 中序遍历求解，prev始终保存的是上个结点的值，与当前节点比较应该要递增
        // if(root == nullptr) return true;
        
        // if(!isValidBST(root->left)) return false;
        
        // if(prev != nullptr && root->val <= prev->val) return false;
        // prev = root;
        // return isValidBST(root->right);

        //  分治
        ResultType res = help(root);
        return res.isBST;
    }
    
    ResultType help(TreeNode *root){
        if(root == nullptr)
            return ResultType(nullptr, nullptr, true);
        
        
        ResultType l = help(root->left);
        ResultType r = help(root->right);
        if(!l.isBST || !r.isBST)
            return ResultType(nullptr, nullptr, false);
        // 左子树中的最大值要小于根节点，否则为false
        if(l.maxNode && l.maxNode->val >= root->val)
            return ResultType(nullptr, nullptr, false);
        // 右子数的中的最小值要大于根节点，否则为false
        if(r.minNode && r.minNode->val <= root->val)
            return ResultType(nullptr, nullptr, false);
        
        return ResultType((r.maxNode ? r.maxNode : root),
                          (l.minNode ? l.minNode : root),
                          true);
    }
};