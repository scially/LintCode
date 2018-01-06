class Solution {
public:
    /*
     * @param str: A string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        sort(str.begin(), str.end());
        for(int i = 1; i < str.size(); i++){
            if(str[i] == str[i-1]) return false;
        }
        return true;
    }
};