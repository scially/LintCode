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
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        // write your code here
        if(root == nullptr) return INT_MIN;
        if(start > end)
            return INT_MIN;
        
        if(start == root->start && end == root->end)
            return root->max;
        
        int mid = root->start + (root->end - root->start) /2;
        int l = INT_MIN, r = INT_MIN;
        if(end <= mid)
            l = query(root->left, start, end);
        else if(start > mid)
            r = query(root->right,start, end);
        else{
            l = query(root->left, start, mid);
            r = query(root->right,mid+1, end);
        }
        return max(l, r);
    }
};