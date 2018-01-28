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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if(preorder.size() == 0 || inorder.size() == 0) return nullptr;
        
        int rootval = preorder[0];
        auto iter = find(inorder.begin(), inorder.end(), rootval);
        if(iter == inorder.end()) return nullptr;
        

        TreeNode *root = new TreeNode(rootval);
        /*
        ** 对于一个树前序[1 2 4 5 3 6 7]
        **           中序[4 2 5 1 6 3 7]
        ** 首先我们根据中序的4在前序找到4的位置，根据前序的遍历顺序必然可知
        ** [4 2 5]是左子树 [6 3 7]是右子数 中序遍历
        ** 它们对应的前序遍历分别是[2 4 5] [3 6 7]
        ** 依次递归即可。
        */
        
        vector<int> pl(preorder.begin()+1, 
                       preorder.begin()+(iter+1-inorder.begin()));
        
        vector<int> pr(preorder.begin()+(iter+1-inorder.begin()),
                       preorder.end());
        vector<int> il(inorder.begin(), iter);
        vector<int> ir(iter + 1,
                       inorder.end());
        
        root->left = buildTree(pl, il);
        root->right = buildTree(pr, ir);
        return root;
    }
    
    void debug(const vector<int>& v){
        // debug
        static auto fcout = [](int x){cout << x << " ";};
        for_each(v.begin(), v.end(), fcout);
        cout << endl;
    }
};