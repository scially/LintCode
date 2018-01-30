/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        // write your code here
        if(root == nullptr) return 0;
        if(start < root->start) start = root->start;
        if(end > root->end) end = root->end;
        if(start > end) return 0;
        if(start == root->start && end == root->end)
            return root->count;
        
        int l = 0, r = 0;
        int mid = root->start + (root->end - root->start) / 2;
        if(end <= mid){
            l = query(root->left, start, end);
        }
        else if(start > mid){
            r = query(root->right, start, end);
        }
        else{
            l = query(root->left, start, mid);
            r = query(root->right,mid+1, end);
        }
        return l+r;
    }
};