/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of segment tree.
     * @param index: index.
     * @param value: value
     * @return: 
     */
    void modify(SegmentTreeNode * root, int index, int value) {
        // write your code here
        query(root,index, value);
    }
    
    int query(SegmentTreeNode *root, int index, int val){
        if(root == nullptr) return INT_MIN;
        if(root->start == root->end){
            if(root->start == index){
                root->max = val;
                return val;
            }
            else{
                return root->max;
            }
        }
        
        int start = root->start, end = root->end, l = INT_MIN, r = INT_MIN;
        int mid = start + (end - start) / 2;
        l = query(root->left, index, val);
        r = query(root->right, index,val);
        root->max = max(l, r);
        return max(l, r);
    }
};