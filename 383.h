class Solution {
public:
    /*
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int max_water = 0, i = 0, j = heights.size()-1;
        int water = 0;
        while(i < j){
            water = min(heights[i], heights[j]) * (j-i);
            max_water = max(water, max_water);
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return max_water;
    }
};