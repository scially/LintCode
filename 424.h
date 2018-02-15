class Solution {
public:
    /*
     * @param tokens: The Reverse Polish Notation
     * @return: the value
     */
    int evalRPN(vector<string> &tokens) {
        // write your code here
        stack<int> s;
        for(auto ite = tokens.begin(); ite != tokens.end(); ite++){
            int num1, num2;
            if(*ite == "+"){
                num2 = s.top(); s.pop();
                num1 = s.top(); s.pop();
                s.push(num1 + num2);
            }
            else if(*ite == "-"){
                num2 = s.top(); s.pop();
                num1 = s.top(); s.pop();
                s.push(num1 - num2);
            }
            else if(*ite == "*"){
                num2 = s.top(); s.pop();
                num1 = s.top(); s.pop();
                s.push(num1 * num2);
            }
            else if(*ite == "/"){
                num2 = s.top(); s.pop();
                num1 = s.top(); s.pop();
                s.push(num1 / num2);
            }
            else{
                s.push(stoi(*ite));
            }
            cout << s.top() << endl;
        }
        return s.top();
    }
};