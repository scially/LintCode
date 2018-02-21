/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 
struct SegmentNode{
public:
    int start, end, min;
    SegmentNode *left, *right;
    SegmentNode(int start, int end, int min) {
        this->start = start;
        this->end = end;
        this->min = min;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    /*
     * @param A: An integer array
     * @param queries: An query list
     * @return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        SegmentNode *root = build(0, A.size() - 1, A);
        // for(int i = 0; i < A.size(); i++)
        //     insert(root, i, A[i]);

        vector<int> r;
        for(int i = 0; i < queries.size(); i++){
            r.push_back(query(root, queries[i].start, queries[i].end));
        }
        
        return r;
    }
private:
    SegmentNode *build(int start, int end, const vector<int> &A){
        if(start == end){
            return new SegmentNode(start, end, A[start]);
        }
        
        SegmentNode *root = new SegmentNode(start, end, INT_MAX);
        int mid = start + (end - start) / 2;
        root->left = build(start, mid, A);
        root->right= build(mid+1, end, A);
        root->min  = min(root->left->min, root->right->min);
        return root;
    }
    
    int query(SegmentNode *root, int start, int end){
        if(root == nullptr) return INT_MAX;
        if(start < root->start) start = root->start;
        if(end   > root->end)   end   = root->end;
        
        if(start == root->start && end == root->end){
            return root->min;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        int lmin = INT_MAX, rmin = INT_MAX;
        if(start >= mid + 1){
            rmin = query(root->right, start, end);
        }
        else if(end <= mid){
            lmin = query(root->left, start, end);
        }
        else{
            lmin = query(root->left, start, mid);
            rmin = query(root->right,mid+1, end);
        }
        return min(lmin, rmin);
    }
};