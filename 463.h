class Solution {
public:
    /*
     * @param A: an integer array
     * @return: 
     */
    void sortIntegers(vector<int> &A) {
        // write your code here
        for(int i = 1; i < A.size(); ++i){
            int val = A[i];
            int j = i;
            while(j > 0 && val < A[j-1]){
                A[j] = A[j-1];
                --j;
            }
            A[j] = val;
        }
    }
};