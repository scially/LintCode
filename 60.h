class Solution {
public:
    /*
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if(A.size()==0) return 0;
        //verson 1
        // int l = 0, r = A.size();
        // while(l < r){
        //     int mid = l + (r-l)/2;
        //     if(target < A[mid]) r = mid ;
        //     else l = mid + 1;
        // }
        
        // if(r >=1 && A[r-1] == target) return r-1;
        // else return r;
        
        //verson2
		// int left = 0, right = A.size();
		// while (left < right) {
		// 	int mid = left + (right - left) / 2;
		// 	if (A[mid] == target) return mid;
		// 	else if (A[mid] < target) left = mid + 1;
		// 	else right = mid;
		// }
		// return right;

        //version3 by wangpei
        int low=0, high=A.size()-1,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(target==A[mid]) return mid;
            else if(target<A[mid]) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};