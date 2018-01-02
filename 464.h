class Solution {
public:
    /*
     * @param A: an integer array
     * @return: 
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        mergesort(A, 0, A.size());
    }
    //[l,r)
    void mergesort(vector<int> &A, int l, int r){
        if(l >= r -1) return;
        int mid = l + (r - l) / 2;
        mergesort(A, l, mid);
        mergesort(A, mid,r);
        if(A[mid - 1] < A[mid]) return;
        merge(A,l,mid,r);
    }
    //[l, mid) and [mid,r)
    void merge(vector<int> &A, int l, int mid, int r){
        int aux[r - l];
        for(int i = 0; i < r - l; i++)
            aux[i] = A[i + l];
        int i = l; // the index of vector aux
        int j = l, k = mid;
        while( j < mid || k < r){
            if(j >= mid){
                A[i] = aux[k-l];
                k++;
            } 
            else if(k >= r){
                A[i] = aux[j-l];
                j++;
            }
            else if(aux[j-l] < aux[k-l]){
                A[i] = aux[j-l];
                j++;
            }
            else{ // aux[j] >= aux[k]
                A[i] = aux[k-l];
                k++;
            }
            i++;
        }
    }
};