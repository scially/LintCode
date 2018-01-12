class Solution {
public:
    /*
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int size = values.size();
        int dp[size+2];
        dp[size-2] = values[size-2] + values[size-1];
        dp[size-1] = values[size-1];
        dp[size] = dp[size+1] = 0;
        
        for(int i = size-3; i>=0; i--){
            //1.第一个人只取第i个硬币,第二个人可以选第i+1或者
            // 第i+1和第i+2个硬币，那么第二个人选过后我们所能
            // 拿到的金币必然是这两种情况最小的那种
            int k1 = values[i] + min(dp[i+2], dp[i+3]);
            //2.第一个人去第i和i+1个硬币,可以类比第一种情况
            int k2 = values[i] + values[i+1] + min(dp[i+3],dp[i+4]);
            
            dp[i] = max(k1, k2);
        }
        
        // dp[0]就是第一个人所能拿到的最大值，要想求出此时第二个人能
        // 拿到的最大值，让所有硬币值减去第一个人拿到的，就是第二个人
        // 的
        int sumvalue = 0;
        for(int i = 0; i < size; i++) 
            sumvalue += values[i];
    
        return dp[0] > sumvalue-dp[0];
    }
};