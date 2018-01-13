class Solution {
public:
    /*
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> nums, int s) {
        // write your code her
        int minlength = INT_MAX;
        int sum = 0, i, j;
        for(i = 0, j = 0; i < nums.size(); i++){
            if(nums[i] >= s) return 1;
            sum += nums[i];
            if (sum >= s) {
				minlength = min(minlength, i - j + 1);

				i = ++j;
				sum = nums[j];
			}
        }
        return minlength == INT_MAX ? -1 : minlength;
    }
};