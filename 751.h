struct SegmentNode{
    int start, end;
    int min;
    SegmentNode *left, *right;
    SegmentNode(int start, int end, int min){
        this->start = start;
        this->end = end;
        this->min = min;
        this->left = nullptr;
        this->right= nullptr;
    }
};

class Solution {
public:
    /**
     * @param A: The prices [i]
     * @param k: 
     * @return: The ans array
     */
    vector<int> business(vector<int> &A, int k) {
        // Write your code here
        SegmentNode *root = build(0, A.size()-1, A);
        vector<int> r;
        for(int i = 0; i <A.size(); i++){
            int min_prices = query(root, i-k, i+k);
            cout << min_prices << endl;
            r.push_back(max(0, A[i] - min_prices));
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
        
        root->min = min(root->left->min, root->right->min);
        return root;
    }
    
    int query(SegmentNode *root, int start, int end){
        if(root == nullptr) return INT_MAX;
        
        if(root->start == start && root->end == end){
            return root->min;
        }
        
        if(start < root->start) start = root->start;
        if(end > root->end) end = root->end;
        
        int mid = root->start + (root->end - root->start) / 2;
        int lmin = INT_MAX, rmin = INT_MAX;
        if(start > mid){
            rmin = query(root->right, start, end);
        }
        else if(end <= mid){
            lmin = query(root->left, start, end);
        }
        else{
            rmin = query(root->left, start, mid);
            lmin = query(root->right, mid+1, end);
        }
        
        return min(lmin, rmin);
    }
};