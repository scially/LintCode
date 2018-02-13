class Solution {
public:
    /*
     * @param path: the original path
     * @return: the simplified path
     */
    string simplifyPath(string &path) {
        // write your code here
        if(path.length() == 0) return "";
        
        // 防止出现 "/" 和 "/."
        path += "/.";
        vector<string> paths = split(path);
        stack<string> s, s2;
        
        for(int i = 0; i < paths.size(); i++){
            if(paths[i] == "") continue;
            else if(paths[i] == "."){
                if(s.empty()) s.push("/");
            }
            else if(paths[i] == ".."){
                if(s.empty()) s.push("/");
                else s.pop();
            }
            else{
                s.push(paths[i]);
            }
        }
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }
        
        ostringstream oss;
        if((!s2.empty()) && s2.top() != "/") oss << "/";
        while(!s2.empty()){
            oss << s2.top() << "/"; 
            s2.pop();
        }
        string pwd =  oss.str();
        return pwd.substr(0, pwd.length() - 1);
    }
    vector<string> split(const string &str, string delim = "/"){
        vector<string> s;
        size_t pos = 0, r;
        while((r = str.find(delim, pos)) != string::npos){
            s.push_back(str.substr(pos, r - pos));
            pos = r + 1;
        }
        if(pos < str.size())
            s.push_back(str.substr(pos));
        return s;
    }
};