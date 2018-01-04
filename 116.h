class Solution {
public:
    /*
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        int size = A.size();
        bool dp[A.size()];
        dp[0] = true;
        for(int i = 1; i < size; i++){
            dp[i] = false;
            for(int j = 0; j < i; j++){
                if(dp[j] && A[j] >= i-j){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size-1];
    }
};