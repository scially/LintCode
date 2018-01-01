class Solution {
public:
    /*
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> res = {-1,-1};
        if(A.size() == 0) return res;
        
        int l = 0, r = A.size();
        while(l < r){
            int mid = l + (r-l)/2;
            if(target <= A[mid]) r = mid;
            else l = mid+1;
        }
        if(A[l] == target) res[0] = l;
        
        l = 0, r = A.size();
        while( l < r){
            int mid =  l + (r-l)/2;
            if(target < A[mid]) r = mid;
            else l = mid + 1;
        }
        if(r>=1 && A[r-1] == target) res[1] = r-1;
        return res;
    }
};