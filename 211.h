class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    bool Permutation(string &A, string &B) {
        // write your code here
        int a[256]{}, b[256]{};

        for(int i = 0; i < A.size(); i++){
           a[A[i]]++; 
        }
        for(int i = 0; i < B.size(); i++){
           b[B[i]]++; 
        }
        
        for(int i = 0; i < 256; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};