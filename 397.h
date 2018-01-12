class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int length = A.size();
        if(!length) return 0;
        
        int L1[length] = {1};
        for(int i = 1; i < length; ++i){
            L1[i] = 1;
            if(A[i] > A[i - 1])
                L1[i] = L1[i - 1] + 1;
                
        }
        
        int L2[length];
        L2[length - 1] = 1;
        for(int i = length - 2; i >= 0; --i){
            L2[i] = 1;
            if(A[i] > A[i + 1])
                L2[i] = L2[i + 1] + 1;
        }
        int max1 = *max_element(L1, L1 + length);
        int max2 = *max_element(L2, L2 + length);
        return max(max1, max2);
    }
};