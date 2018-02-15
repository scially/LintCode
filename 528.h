/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        process(nestedList);
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        int n = s.top();
        s.pop();
        return n;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        return !s.empty();
    }
private:
    stack<int> s;
    void process(const vector<NestedInteger> &nestedList){
        for(auto ite = nestedList.rbegin(); ite != nestedList.rend(); ite++){
            if(ite->isInteger()){
                s.push(ite->getInteger());
            }
            else{
                const vector<NestedInteger> v = ite->getList();
                process(v);
            }
        }
    }
    
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */