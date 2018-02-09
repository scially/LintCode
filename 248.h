struct SegmentTree{
public:
    int start, end;
    int count;
    SegmentTree *left, *right;
    SegmentTree(int start, int end, int count = 0){
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
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        SegmentTree *root = build(0, 10000);
        
        for(int a : A)
            insert(root, a);
        vector<int> q;
        for(int a : queries)
            q.push_back(query(root, 0, a - 1));
        return q;
    }
private:
    SegmentTree *build(int start, int end){
        if(start == end) 
            return new SegmentTree(start, end);
        if(start > end) return nullptr;
        
        SegmentTree *root = new SegmentTree(start, end);
        int mid = start + (end - start) / 2;
        root->left = build(start, mid);
        root->right= build(mid+1, end);
        return root;
    }
    
    // 插入元素
    void insert(SegmentTree* root, int val){
        if(root == nullptr) 
            return;
        if(root->start == val && root->end == val){
            root->count += 1;
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if(val <= mid)
            insert(root->left, val);
        else
            insert(root->right, val);
        
        root->count = root->left->count + root->right->count;
    }
    
    int query(SegmentTree *root, int start, int end){
        if(root == nullptr) return 0;
        if(end > root->end) end = root->end;
        if(start < root->start) start = root->start;
        if(start == root->start && end == root->end)
            return root->count;
        int mid = root->start + (root->end - root->start) / 2;
        int l = 0, r = 0;
        if(end <= mid){
            l = query(root->left, start, end);
        }
        else if(start > mid){
            r = query(root->right, start, end);
        }
        else{
            l = query(root->left, start, mid);
            r = query(root->right, mid + 1, end);
        }
        return l + r;
    }
};