class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        // write your code here
        
        // 优化前
        // 这样时间复杂度是O(n3),会LTE
        // 考虑到字典中最大单词长度，从后向前寻找。
        // 当切分的单词长度大于最大长度时，中断循环
        
        int length = s.size(), maxlength = 0;
        for(auto iter = dict.begin(); iter != dict.end(); iter++){
            maxlength = max<int>(maxlength, (*iter).size());
        }
        //dp[i] 表示前i个字符是否可以分割
        bool dp[length+1];
        dp[0] = true; //空字符串必然可以切分
        for(int i = 1; i <= s.size(); i++){
            dp[i] = false;
            for(int j = i; j >= 1; j--){
                int subsize = i - j + 1;
                if(subsize > maxlength) break;
                
                string substr = s.substr(j-1, subsize);
                if(dp[j-1] && dict.find(substr) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[length];
    }
};