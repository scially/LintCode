
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
    int majorityNumber(vector<int> &nums, int k) {
        // write your code here
        map<int,int> count;
        for(int i = 0; i < nums.size(); i++){
            if(count.find(nums[i]) != count.end()){
                count[nums[i]]++;
            }
            else{
                count[nums[i]] = 1;
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(count[nums[i]] > nums.size()/k)
                return nums[i];
        }
    }
};