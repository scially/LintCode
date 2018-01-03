class Solution {
public:
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int>& A) {
        // write your code here
        int l = 0, r = A.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(A[mid-1]<A[mid] && A[mid]>A[mid+1]) return mid;
            else if(A[mid] < A[mid+1]) l = mid + 1;
            else r = mid;
        }
        return l; // 不会执行到这一步，因为题中确保至少存在一个峰值
    }
};