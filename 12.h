// 要注意pop的情况，当栈pop的时候最小值可能会发生变化

class MinStack {
    stack<int> s1;
    stack<int> s2;
public:
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        s1.push(number);
        if(s2.empty()){
            s2.push(number);
        }
        else{
            int _min = ::min(s2.top(), number);
            s2.push(_min);
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        if(!s1.empty()){
            int r = s1.top();
            s1.pop();
            s2.pop();
            return r;
        }
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here
        if(!s2.empty()) return s2.top();
    }
};