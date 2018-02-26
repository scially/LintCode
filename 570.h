class Solution {
public:
    /*
     * @param n: An integer
     * @param str: a string with number from 1-n in random order and miss one number
     * @return: An integer
     */
    int findMissing2(int n, string &str) {
        // write your code here
        vector<bool> visited(n+1, false); //第一位不用
        return findMissing2(n, str, 0, visited);
    }
    
    // n <= 30
    int findMissing2(int n, string &str, int start, vector<bool> &visited){
        if(start >= str.size()){
            for(int i = 1; i <= n; i++){
                if(!visited[i]) return i;
            }
            return -1;
        }
        
        if(str[start] == '0') return -1;  // 数字划分失败
        
        // 可能是一位数或者两位数
        for(int i = start; i < start + 3 && i < str.size(); i++){
            string s = str.substr(start, i-start+1);
            int num = stoi(s);
            
            if(num > 0 && num <= n && !visited[num]){ //[1,n]
                visited[num] = true;
                int miss =  findMissing2(n, str, i+1, visited);
                if(miss != -1) return miss;
                
                visited[num] = false;
            }
        }
        return -1;  // must
    }
};