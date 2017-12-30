class Solution {
public:
    /*
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> ret;
        int i = 0, j = 0;
        while(i < A.size() || j < B.size()){
            if(i >= A.size()){
                ret.push_back(B[j]);
                j++;
            }
            else if(j >= B.size()){
                ret.push_back(A[i]);
                i++;
            }
            else if(A[i] < B[j]){
                ret.push_back(A[i]);
                i++;
            }
            else {
                ret.push_back(B[j]);
                j++;
            }
        }
        return ret;
    }
};