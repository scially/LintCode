
class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int A_aux[m];
        for(int i = 0; i < m; i++) A_aux[i] = A[i];
        int j = 0, k = 0;
        for(int i = 0; i < m+n; i++){
            if(j >= m) {
                A[i] = B[k];
                k++;
            }
            else if(k >= n){
                A[i] = A_aux[j];
                j++;
            }
            else if(A_aux[j] <= B[k]){
                A[i] = A_aux[j++];
            }
            else{
                A[i] = B[k++];
            }
        }
    }
};