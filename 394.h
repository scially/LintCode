class Solution {
public:
    /*
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
       bool dp[n+1];
       dp[0] = false; dp[1] = dp[2] = true;
        
        for(int i = 3; i <= n; i++){
            //if(dp[i-1] == true && dp[i-2] == true) dp[i] = false;
            dp[i] = (!dp[i-1] || !dp[i-2]);
        }
        return dp[n];
        
    }
};