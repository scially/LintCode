class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size() == 0) return 0;
        int i = 0;
        for(int j = i+1;j < nums.size();){
            if(nums[j] == nums[i]){
                j++;
                continue;
            } 
            nums[++i] = nums[j++];
        }
        return i+1;
    }
};