class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size() == 0 ) return 0;
        int i = 0, count = 0;
        for(int j = i+1; j <nums.size();j++){
            if(count < 1 && nums[j] == nums[i]){
                count++;
                nums[++i] = nums[j];
            }
            else if(nums[j] != nums[i]){
                nums[++i] = nums[j];
                count = 0;
            }
        }
        return i+1;
    }
};