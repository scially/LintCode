class Solution {
public:
    /*
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        
        int l = 0, r = m;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(target == matrix[mid][0]) return true;
            else if(target < matrix[mid][0]) r = mid;
            else l = mid + 1;
        }
        
        int row = l >= 1 ? l-1 : 0;
        //cout << row << endl;
        l = 0;
        r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(target == matrix[row][mid]) return true;
            else if(target < matrix[row][mid]) r = mid;
            else l = mid + 1;
        }
        return false;
    }
};