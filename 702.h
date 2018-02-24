class Solution {
public:
    /*
     * @param : the 1st string
     * @param : the 2nd string
     * @return: uncommon characters of given strings
     */
    string concatenetedString(string &s1, string &s2) {
        // write your code here
        int ch[256]{};
        for(int i = 0; i < s2.size(); i++){
            ch[s2[i]] = 1;
        }
        ostringstream oss;
        for(int i = 0; i < s1.size(); i++){
            if(!ch[s1[i]]){ 
                oss << s1[i];
            }
            else{
                ch[s1[i]] ++;
            }
        }
        for(int i = 0; i < s2.size(); i++){
            if(ch[s2[i]] < 2) oss << s2[i];
        }
        return oss.str();
    }
};