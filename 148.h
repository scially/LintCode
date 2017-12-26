class Solution {
public:
    /*
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        partition(nums, 0, nums.size());
    }
    
	void partition(vector<int> &nums, int l, int r) {
		const int v = 1;
		int i = l, lt = l - 1, gt = r;
		while(i < gt){
		    if(nums[i] == v){
		        i++;
		    }
		    else if(nums[i] < v){
		        swap(nums[i], nums[++lt]);
		        i++;
		    }
		    else{
		        swap(nums[i], nums[--gt]);
		    }
		}
	}
};