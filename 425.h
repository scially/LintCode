class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here
        vector<string> v;
        string tmp;
        letter(digits, 0, tmp, v);
        return v;
    }
private:
    void letter(string &digits, int start, string &str, vector<string> &v){
        if(start == digits.size()){
            if(str.size() != 0 && str.size() == digits.size()) 
                v.push_back(str);
            return;
        }
        
        for(int i = start; i < digits.size(); i++){
            int index = digits[i] - '0';
            if(index == 0 || index == 1) continue;
            
            for(int j = 0; j < 4 && digit[index][j] ; j++){
                string oldstr = str;
                str += digit[index][j];
                letter(digits, i+1, str, v);
                str = oldstr;
            }
        }
    }
    const char digit[10][5] = {
        "",       // 0 
        "",       // 1
        "abc",    // 2
        "def",    // 3
        "ghi",    // 4
        "jkl",    // 5
        "mno",    // 6
        "pqrs",   // 7
        "tuv",    // 8
        "wxyz"    // 9
    };
};