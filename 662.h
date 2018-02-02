// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    /**
     * @param n an integer
     * @return the number you guess
     */
    int guessNumber(int n) {
        // Write your code here
        // error
        // int l = 1, r = n + 1 

        // verson 1
        int l = 1, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            int t = guess(mid);
            if(t == 0) return mid;
            else if(t < 0) r = mid;
            else l = mid + 1;
        }
        return l;

        // verson 2 wiki
        int l = 1, r = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int t = guess(mid);
            if(t == 0) return mid;
            else if(t < 0) r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }
};