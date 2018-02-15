class Solution {
public:
    /*
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        // write your code here
        ostringstream oss;
        stack<char> st;
        string str;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ']'){
                stack<char> st2;
                str = "";
                while(!st.empty() && st.top() != '['){
                    str += st.top();
                    st.pop();
                }
                reverse(str.begin(), str.end());
                st.pop(); // pop '['
                int num = 0, base = 1;
                while(!st.empty() && st.top() <= '9' && st.top() >= '0'){
                    num += (st.top() - '0') * base;
                    base *= 10;
                    st.pop();
                }
                cout << num << endl;
                for(int j = 0; j < num; j++){
                    for(int j = 0; j < str.size(); j++){
                        st.push(str[j]);
                    }
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            oss << st.top();
            st.pop();
        }
        str = oss.str();
        reverse(str.begin(), str.end());
        return str;
    }
};