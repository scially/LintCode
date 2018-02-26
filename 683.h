class Solution {
public:
    /*
     * @param : A string
     * @param : A set of word
     * @return: the number of possible sentences.
     */
    int wordBreak3(string& s, unordered_set<string>& dict) {
        // Write your code here
        unordered_set<string> _dict;
        for(auto iter = dict.begin(); iter != dict.end(); iter++){
            _dict.insert(tolower(*iter));
        }
        s = tolower(s);
        
        vector<vector<string>> v;
        vector<string> r;
        wordBreak3(s, _dict, v, r, 0);
        return v.size();
    }
    void wordBreak3(string &s, unordered_set<string> &dict, 
                vector<vector<string>> &v, vector<string> &r, int start){
        if(start == s.size()){
            v.push_back(r);
        }
        
        for(int i = start; i < s.size(); i++){
            string word = s.substr(start, i - start + 1);
            if(dict.find(word) != dict.end()){
                r.push_back(word);
                wordBreak3(s, dict, v, r, i+1);
                r.pop_back();
            }
        }
    }
    string tolower(const string &str){
        string lower = str;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        return lower;
    }
};