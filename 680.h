class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        // write your code here
        vector<string> v;
        vector<vector<string>> r;
        splitString(s, v, r, 0);
        return r;
    }
    void splitString(string &s, vector<string> &v, vector<vector<string>> &r, int start){
        if(start == s.size()) {
            r.push_back(v);
            return;
        }
        if(start < s.size()){
            v.push_back(s.substr(start,1));
            splitString(s,v,r, start+1);
            v.pop_back();
        }
        if(start < s.size() - 1){
            v.push_back(s.substr(start, 2));
            splitString(s, v, r, start+2);
            v.pop_back();
        }
    }
};