class Solution {
public:
    /*
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean 
     */
    bool search(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0) return false;

        int l = 0, r = A.size();
        while(l < r){
            int mid = l + (r-l)/2;
            //不断的搜索有序区间
            if(A[mid] == target) return true;
            else if(A[mid] <= A[r-1]){ //右边为有序区间
                if(target > A[mid] && target <= A[r-1]) l = mid+1;
                else r = mid;
            }
            else{ //A[mid] > A[l]左边为有序区间
                if(target >= A[l] && target < A[mid]) r = mid; 
                else l = mid+1;
            }
        }
        return false;
    }
};