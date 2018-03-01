class Solution {
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // write your code here
        
        if(n <= 0) return vector<string>();
        vector<string> r;
        string tmp;
        helper(n, 0, 0, r, tmp);
        return r;
    }
    void helper(int n, int left, int right, vector<string> &v, string &tmp){
        if(left == n && right == n){
            v.push_back(tmp);
            return;
        }
        if(left < n){
            string old_tmp = tmp;
            tmp += '(';
            helper(n, left+1, right, v, tmp);
            tmp = old_tmp;
        }
        if(left > right && right < n){
            string old_tmp = tmp;
            tmp += ')';
            helper(n, left, right+1, v, tmp);
            tmp = old_tmp;
        }
    }
};