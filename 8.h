class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // write your code here
        if(str.size() == 0) return;
        
        offset = str.size() - 1 - offset % str.size();
        reverseString(str, 0, offset);
        reverseString(str, offset+1, str.size()-1);
        reverseString(str, 0, str.size()-1);
    }
    
    // reverse str[start, end]
    void reverseString(string &str, int start, int end){
        while(start < end){
            swap(str[start++], str[end--]);
        }
    }
};