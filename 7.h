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
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        // write your code here
        ostringstream oss;
        vector<TreeNode*> v;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front(); q.pop();
            v.push_back(node);
            if(node == nullptr) continue;
            
            q.push(node->left);
            q.push(node->right);
        }
        
        while(v.size() > 0 && v[v.size()-1] == nullptr){
            v.pop_back();
        }
        if(v.size() == 0) return "{}";
        
        oss << "{" << v[0]->val;
        for(int i = 1; i < v.size(); i++){
            if(v[i] != nullptr){
                oss << "," << v[i]->val;
            }
            else
                oss << ",#";
        }
        oss << "}";
        cout << oss.str();
        return oss.str();
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        // write your code here
        if( data == "{}" ) return nullptr;
        
        vector<string> datas = split(data.substr(1, data.length()-2), ",");
        
        TreeNode *root = new TreeNode(stoi(datas[0]));
        queue<TreeNode*> q; 
        q.push(root);
        bool isLeftNode = true;
        for(int i = 1; i < datas.size(); i++){
            if(datas[i] != "#"){
                TreeNode *node1 = q.front();
                TreeNode *node2 = new TreeNode(stoi(datas[i]));
                if(isLeftNode){
                    node1->left = node2;
                }
                else{
                    node1->right = node2;
                }
                q.push(node2);
            }
            else{  // == "#"
                
            }
            if(!isLeftNode){
                q.pop();
            }
            isLeftNode = !isLeftNode;
        }
        return root;
    }
    
    static vector<string> split(const string &str, string delim){
        vector<string> r;
        
        int index, lastindex = 0;
        while((index = str.find(delim, lastindex)) != string::npos){
            r.push_back(str.substr(lastindex, index - lastindex));
            lastindex = index + delim.length();
        }
        if(lastindex != str.size()){
            r.push_back(str.substr(lastindex));
        }
        return r;
    }

};