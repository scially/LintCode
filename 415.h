class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
        int begin = 0, end = s.size();
        while(begin < end){
            while(begin < s.size() && !isalnum(s[begin])){
                begin++;
            }
            while(end >= 0 && !isalnum(s[end])){
                end--;
            }
          
            if(tolower(s[begin++]) != tolower(s[end--])) return false;
        }
        return true;
    }
};