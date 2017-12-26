class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        // 找第k大元素，实际上就是找第n+1-k名元素（从小到大）
        return kthLargestElement(nums.size() + 1 - n, nums, 0, nums.size());
    }
    
    int kthLargestElement(int n, vector<int> &nums, int l, int r){
        //if (l >= r) return nums[l];
	    int p = partition(nums, l, r);
	    if (n == p + 1) return nums[n-1];
	    else if (n < p + 1) return kthLargestElement(n, nums, l, p);
	    else return kthLargestElement(n, nums, p + 1, r);
    }

    int partition(vector<int> &nums, int l, int r){ //[l,r)
        int j = l;
        for(int i = l + 1; i < r; i++){
            if(nums[i] < nums[l]){
                swap(nums[i], nums[++j]);
            }
        }
        swap(nums[l], nums[j]);
        return j;
    }
};