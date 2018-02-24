class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
        // write your code here
        vector<string> v;
        int i = 0, j = 0;
        while(i < s.size()){
            for(j = i; j < s.size() && s[j] == ' '; j++) {}
            for(i = j; j < s.size() && s[j] != ' '; j++) {}
            if(i >= s.size()) break;
            v.push_back(s.substr(i, j-i));
            i = j + 1;
        }
        // while(i < s.size() && s[i++] == ' ') {}
        // if(i < s.size()) v.push_back(s.substr(i));
        
        ostringstream oss;
        for(int i = v.size() - 1; i >= 0; i--){
            oss << v[i];
            if(i != 0) oss << ' ';
        }
        return oss.str();
    }
};