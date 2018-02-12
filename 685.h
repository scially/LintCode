class Solution {
public:
    /*
     * @param : a continuous stream of numbers
     * @param : a number
     * @return: returns the first unique number
     */
    int firstUniqueNumber(vector<int> nums, int number) {
        // Write your code here
        if(nums.size() == 0) return -1;
        map<int, int> m;
        for(int num : nums){
            if(m.find(num) == m.end()) m[num] = 1;
            else  m[num]++;
            if(num == number) break;
        }
        // not found number
        if(m.find(number) == m.end()) 
            return -1;
        
        for(int num : nums){
            if(m[num] == 1) return num;
            if(num == number) break;
        }
        return -1;
    }
};