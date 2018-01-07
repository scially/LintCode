class Solution {
public:
    /*
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int _max;
        int water = 0;
        int maxIndex = 0;
        //找到数组中最大值
        for(int i = 1; i < heights.size(); i++){
            if(heights[i] > heights[maxIndex])
                maxIndex = i;
        }
        //前后遍历
        _max = 0;
        for(int i = 0; i < maxIndex; i++){
            _max = max(_max, heights[i]);
            water += _max - heights[i];
        }
        //这里不从能maxIndex -> size-1！
        _max = 0;
        for(int i = heights.size()-1; i > maxIndex; i--){
            _max = max(_max, heights[i]);
            water += _max - heights[i];
        }
        return water;
    }
};