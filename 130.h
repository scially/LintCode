#define LEFTNODE(i)   ((i) * 2 + 1)
#define RIGHTNODE(i)  ((i) * 2 + 2)

class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        // write your code here
        if(A.size() <= 1) return;
        int p = (A.size() - 1) / 2;
        while(p >= 0){
            shiftDown(p, A);
            p--;
        }
    }
    
private:
    void shiftDown(int i, vector<int> &A){
        while(LEFTNODE(i) < A.size()){
            int j = LEFTNODE(i);
            if(RIGHTNODE(i) < A.size() && A[j] > A[RIGHTNODE(i)])
                j = RIGHTNODE(i);
            if(A[i] <= A[j]) break;
            swap(A[i], A[j]);
            i = j;
        }
    }
};