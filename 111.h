class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        int a = 1,b = 1;
        int j = 0;
        while(j++ < n){
            a = a + b;
            b = a - b;
        }
        return b;
    }
};
