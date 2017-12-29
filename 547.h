class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        // write your code here
        vector<int> ret;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		while (i<nums1.size() && j < nums2.size()) {
			if (nums1[i] == nums2[j]) {
				if (i == 0 || nums1[i] != nums1[i - 1])
					ret.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] > nums2[j]) j++;
			else i++;
		}
		return ret;
    }
};