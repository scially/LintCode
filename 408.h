class Solution {
public:
    /**
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
        // write your code here
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        bool add_flag = false;
        int i = 0;
        ostringstream oss;
        for(; i < a.size() && i < b.size(); i++){
            int add = a[i] - '0' + b[i] - '0' + (add_flag ? 1 :0);
            add_flag = add >= 2;
            add = add % 2;
            oss << add;
        }
        
        while(i < a.size()){
            int add = a[i++] - '0' + (add_flag ? 1 :0);
            add_flag = add >= 2;
            add = add % 2;
            oss << add;
        }
        while(i < b.size()){
            int add = b[i++] - '0' + (add_flag ? 1 :0);
            add_flag = add >= 2;
            add = add % 2;
            oss << add;
        }

        if(add_flag) oss << 1;
        string str = oss.str();
        reverse(str.begin(), str.end());
        return str;
    }
};