class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        s1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int p = top();
        s2.pop();
        return p;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        reverse();
        return s2.top();
    }
    
private:
    stack<int> s1;
    stack<int> s2;
    
    void reverse(){
        if(!s2.empty()) return;
        
        while(!s1.empty()){
            //cout << "reverse " << s1.top() << endl;
            s2.push(s1.top());
            s1.pop();
        }
    }
};