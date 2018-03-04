class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        // write your code here
        int dp[A.size()];
        for(int i = 0; i < A.size(); i++)
            dp[i] = 0;
        for(int i = 1; i < A.size(); i++){
            int min_step = INT_MAX;
            for(int j = 0; j < i; j++){
                if(dp[j] != INT_MAX && A[j] >= i-j)
                    min_step = min(min_step, dp[j] + 1);
            }
            
            dp[i] = min_step;
        }
        return dp[A.size() - 1];
    }
};