class Solution {
public:
    /**
     * @param s: A string
     * @return: the length of last word
     */
    int lengthOfLastWord(string &s) {
        // write your code here
        int len = 0, i = 0, j = 0;
        while(i < s.size()){
            while(i < s.size() && s[i] == ' ') i++;
            if(i >= s.size()) break;
            for(j = i; j < s.size() && s[j] != ' ' ; j++) {}
            len = j - i;
            i = j + 1;
        }
        return len;
    }
};