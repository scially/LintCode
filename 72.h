class Solution {
public:
    /*
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        
        int val = *(postorder.end()-1);  
        auto iter = find(inorder.begin(), inorder.end(), val);
        
        TreeNode *root = new TreeNode(val);
        vector<int> il(inorder.begin(), iter);
        vector<int> ir(iter+1, inorder.end());
        vector<int> pl(postorder.begin(), 
                       postorder.begin() + (iter-inorder.begin()));
        vector<int> pr(postorder.begin() + (iter-inorder.begin()),
                       postorder.end()-1);
        
        root->left = buildTree(il, pl);
        root->right= buildTree(ir, pr);
        return root;
    }

};
