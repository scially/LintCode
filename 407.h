class Solution {
public:
    /*
     * @param digits: a number represented as an array of digits
     * @return: the result
     */
    vector<int> plusOne(vector<int> &digits) {
        // write your code here
        int plus = 1;
        vector<int> v;
        for(int i = digits.size()-1; i >= 0; i--){
            int num = digits[i] + plus;
            plus = num / 10;
            num %= 10;
            v.push_back(num);
        }
        if(plus != 0) v.push_back(plus);
        reverse(v.begin(), v.end());
        return v;
    }
};