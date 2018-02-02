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
        // 这里之所以要这样判断的情况，就是因为我们定义的数组的范围是[l,r)
        if(r>=1 && A[r-1] == target) res[1] = r-1;
        // 或者这样 使用l也可以
        //range[1] = (l >= 1 && A[l-1] == target)? l - 1 : -1;
        return res;
    }
};