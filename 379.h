class Solution {
public:
    /*
     * @param nums: n non-negative integer array
     * @return: A string
     */
    string minNumber(vector<int> nums) {
        // write your code here
        sort(nums.begin(), nums.end(), less);
    
        string res = "";
        if(nums.size()==0) return res;
        int i = 0;
        
        for(; i < nums.size(); i++){
            if(nums[i] != 0 ) break;
        }
        for(; i < nums.size(); i++){
            res += to_string(nums[i]);
        }
        
        if(res == "") return "0";
        else return res;
    }
    static bool less(int num1, int num2){
        string str1 = to_string(num1);
        string str2 = to_string(num2);
        
        string res1 = str1 + str2;
        string res2 = str2 + str1;
        return res1 < res2;
    }
};