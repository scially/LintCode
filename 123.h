class Solution {
public:
    /*
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) {
        // write your code here
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(exist(board, word, visited, i, j, 0)) 
                        return true;
                }
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited,
            int x, int y, int start){
            
            if(start >= word.size()){
                return true;
            }
            if(x >= board.size() || x < 0 
               || y < 0 || y >= board[0].size()
               || board[x][y] != word[start]
               || visited[x][y]){
                return false;
            }
            
            // visited[x][y] = true;
            // bool hor1 = false, hor2 = false, ver1 = false, ver2 = false;
            // if (exist(board, word, visited, x, y-1, start+1)
            //     || exist(board, word, visited, x, y+1, start+1)
            //     || exist(board, word, visited, x-1, y, start+1)
            //     || exist(board, word, visited, x+1, y, start+1))
            //     return true;
           
            // visited[x][y] = false;  // 回溯
            
            // return false;
            // 上面这段代码会TLE, why?
            
            visited[x][y] = true;
            bool hor1 = false, hor2 = false, ver1 = false, ver2 = false;
            if (exist(board, word, visited, x, y-1, start+1)
                || exist(board, word, visited, x, y+1, start+1)
                || exist(board, word, visited, x-1, y, start+1)
                || exist(board, word, visited, x+1, y, start+1))
                return true;
           
            visited[x][y] = false;  // 回溯
            
            return false;
    }
};