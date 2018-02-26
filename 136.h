class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        // write your code here
        vector<string> v;
        vector<vector<string>> r;
        partition(s, v, r, 0);
        return r;
    }
private:
    void partition(string &s, vector<string> &v, vector<vector<string>> &r,
                   int start){
        if(start == s.size()){
            r.push_back(v);
            return;
        }
        
        for(int i = start; i < s.size(); i++){
            string str = s.substr(start, i-start+1);
            if(isPalindrome(str)){
                v.push_back(str);
                partition(s, v, r, i+1);
                v.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string &s){
        for(int start = 0, end = s.size()-1; start < end; start++, end--){
            if(s[start] != s[end])
                return false;
        }
        return true;
    }
};