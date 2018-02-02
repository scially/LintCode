class Solution {
public:
    /*
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        long l = 0, r = x;
        while(l < r){
            long mid = l + (r - l) / 2;
            cout << mid << endl;
            if(mid * mid == x) return mid;
            else if(mid * mid <= x) l = mid + 1;
            else r = mid;
        }
        return l * l == x ? l: l - 1;
    }
};