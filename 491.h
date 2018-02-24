class Solution {
public:
    /**
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        // write your code here
        string str = to_string(num);
        int start = 0, end = str.size() -1;
        while(start < end){
            if(str[start++] != str[end--]) return false;
        }
        return true;
    }
};