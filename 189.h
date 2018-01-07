class Solution {
public:
    /*
     * @param A: An array of integers
     * @return: An integer
     */
    int firstMissingPositive(vector<int> &A) {
        // write your code here
        // 1
        // sort(A.begin(), A.end());
        // A.push_back(INT_MAX);
        // for(int i = 0; i < A.size(); i++){
        //     if(A[i]-A[i-1] <=1) continue;  // -1 0, 2 2
        //     if(A[i-1]<0 && A[i]-A[i-1]==2) continue;  // -1 1
        //     if(A[i-1]>=0){ // 0 2
        //         return A[i-1]+1;
        //     }
        // }
        // return 1;
        
        // 2
        int size = A.size();
        for(int i = 0; i < size; i++){
            if(A[i] == i+1) continue;
            if(A[i] > 0 && A[i] <= size){
                swap(A[i], A[A[i]-1]);
                if(A[i] != A[A[i]-1])
                    i--;
            }
        }
        
        for(int i = 0; i < size; i++){
            if(A[i] != i+1) return i+1;
        }
        return size+1;
    }
};