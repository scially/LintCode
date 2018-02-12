class Solution {
public:
    /*
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        // write your code here
        
        // verson 1
        // s += '#';
        // stack<char> st;
        // st.push('#');
        // for(int i = 0; i < s.length(); i++){
        //     char c = st.top();
        //     if((c == '(' && s[i] == ')') ||
        //       (c == '[' && s[i] == ']') ||
        //       (c == '{' && s[i] == '}') ||
        //       (c == '#' && s[i] == '#')){
        //           st.pop();
        //       }
        //     else
        //         st.push(s[i]);
        // }
        
        // return st.empty();
        
        // verson 2
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            if(s[i] == ')'){
                if(st.empty() || st.top() != '(') 
                    return false;
                st.pop();
            }
            if(s[i] == ']'){
                if(st.empty() || st.top() != '[') 
                    return false;
                st.pop();
            }
            if(s[i] == '}'){
                if(st.empty() || st.top() != '{') 
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};