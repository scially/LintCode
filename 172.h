class Solution {
public:
    /*
     * @param A: A list of integers
     * @param elem: An integer
     * @return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        if(A.empty()) return 0;
        int i, j;
        for(i =-1, j=i+1; j<A.size(); j++){
            if(A[j] == elem) continue;
            //A[j] != A[i]
            A[++i]=A[j];
        }
        return i+1;
    }
};