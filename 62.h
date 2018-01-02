class Solution {
public:
    /*
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0) return -1;
        // int rotateBase = 0;
        // for(;rotateBase < A.size()-1 && A[rotateBase] < A[rotateBase+1]; rotateBase++);
        // int i1 = binarySearch(A, 0, rotateBase+1, target);
        // int i2 = binarySearch(A, rotateBase, A.size(), target);
        // if(i1 != -1) return i1;
        // else if(i2 != -1) return i2;
        // else return -1;
        
        int l = 0, r = A.size();
        while(l < r){
            int mid = l + (r-l)/2;
            //不断的搜索有序区间
            if(A[mid] == target) return mid;
            else if(A[mid] < A[r-1]){ //右边为有序区间
                if(target > A[mid] && target <= A[r-1]) l = mid+1;
                else r = mid;
            }
            else{ //A[mid] > A[l]左边为有序区间
                if(target >= A[l] && target < A[mid]) r = mid; 
                else l = mid+1;
            }
        }
        return -1;
    }
    // don't use
    // A[l,r) 
    int binarySearch(vector<int> &A, int l, int r, int target){
        while(l < r){
            int mid = l + (r-l)/2;
            if(A[mid] == target) return mid;
            else if(A[mid] < target) l = mid+1;
            else r = mid;
        }
        return -1;
    }
};