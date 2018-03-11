class Solution {
public:
    /**
     * @param s: A string
     * @return: An integer
     */
    int minCut(string &s) {
        // write your code here
        int length = s.size();
        int dp[length+1]{};
        dp[0] = -1;
        for(int i = 1; i <= s.size(); i++){
            int __min = i-1;
            for(int j = 1; j <= i; j++){
                bool can = ispalinrome(s, j-1, i-1);
                if(can)
                    __min = min(__min, dp[j-1]+1);
            }
            dp[i] = __min;
        }
        return dp[length];
    }
private:
    bool ispalinrome(string &s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};