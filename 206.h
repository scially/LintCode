/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

struct SegmentNode{
    int start, end;
    long long count;
    SegmentNode *left, *right;
    SegmentNode(int start, int end, long long count = 0){
        this->start = start;
        this->end   = end;
        this->count = count;
        this->left  = nullptr;
        this->right = nullptr;
    }
};

class Solution {
public:
    /*
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        SegmentNode *root = build(0, A.size() - 1, A);
        vector<long long> r;
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
        
        SegmentNode *root = new SegmentNode(start, end);
        int mid = start + (end - start) / 2;
        root->left = build(start, mid, A);
        root->right= build(mid+1, end, A);
        root->count= root->left->count + root->right->count;
        return root;
    }
    
    long long query(SegmentNode *root, int start, int end){
        if(root == nullptr) return 0;
        if(start < root->start) start = root->start;
        if(end   > root->end)   end   = root->end;
        if(root->start == start  && root->end == end){
            return root->count;
        }
        
        long long l = 0, r = 0;
        int mid = root->start + (root->end - root->start) / 2;
        if(start > mid){
            r = query(root->right, start, end);
        }
        else if(end <= mid){
            l = query(root->left, start, end);
        }
        else{
            l = query(root->left, start, mid);
            r = query(root->right,mid+1, end);
        }
        return l+ r;
    }
};