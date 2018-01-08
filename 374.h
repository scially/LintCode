class Solution {
public:
    /*
     * @param matrix: a matrix of m x n elements
     * @return: an integer list
     */
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        // write your code here
        vector<int> ret;
        if(matrix.size() == 0 )
            return ret;
        spiralOrder(matrix, ret, 0, 0, 1, matrix.size(), matrix[0].size(), 1);
        return ret;
    }
    // axis: 0 row, 1,  col
    // num :
    // flag: 1 increase, -1 decrease
    void spiralOrder(const vector<vector<int>> &matrix, vector<int> &ret,
                     int row, int col, int flag, int rows, int cols, int axis){
        if(rows == 0 || cols == 0){
            //ret.push_back(matrix[row][col]);
            return;
        }
        
        if(axis == 0){ // row
            if(flag > 0){
                for(int i = row; i < row + rows; i++){
                    ret.push_back(matrix[i][col]);
                }
                spiralOrder(matrix, ret, row+rows-1, col-1, -1, rows, cols-1, 1);
            }else{ // flag < 0
                for(int i = row; i > row - rows; i--){
                    ret.push_back(matrix[i][col]);
                }
                spiralOrder(matrix, ret, row-rows+1, col+1, 1, rows, cols-1, 1);
            }
        }
        else if(axis == 1){ // col
            if(flag > 0){
                for(int j = col; j < col + cols; j++){
                    ret.push_back(matrix[row][j]);
                }
                spiralOrder(matrix, ret, row+1, col+cols-1, 1, rows-1, cols,0);
            }else{ // flag < 0
                for(int j = col; j > col - cols; j--){
                    ret.push_back(matrix[row][j]);
                }
                spiralOrder(matrix, ret, row-1, col-cols+1, -1, rows-1, cols, 0);
            }
        }
    }
};