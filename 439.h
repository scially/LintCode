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
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int> &A) {
        // write your code here
        return build(0, A.size() - 1, A);
    }
    SegmentTreeNode *build(int start, int end, const vector<int> &A){
        if(start > end){
            return nullptr;
        } 
        if(start == end){
            return new SegmentTreeNode(start, end, A[start]);
        }
        
        SegmentTreeNode *root = new SegmentTreeNode(start, end, INT_MIN);
        int mid = start + (end - start) / 2;
        root->left = build(start, mid, A);
        root->right= build(mid+1, end, A);
        root->max = max(root->left->max, root->right->max);
        return root;
    }
};