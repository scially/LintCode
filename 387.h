class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(B.begin(), B.end());
        int smallest = INT_MAX;
        for(int i = 0; i < A.size(); i++){
            find_k(B, 0, B.size(), A[i], smallest);
        }
        return smallest;
    }
    void find_k(const vector<int> &B, int l, int r, int k, int &smalle){
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        if(k == B[mid]){
            smalle = 0;
            return;
        }
        
        else if(k < B[mid]){
            if(smalle > abs(k-B[mid])) smalle = abs(k-B[mid]);
            find_k(B, l, mid, k, smalle);
        }
        else{
            if(smalle > abs(k-B[mid])) smalle = abs(k-B[mid]);
            find_k(B, mid + 1, r, k, smalle);
        }
    }
};