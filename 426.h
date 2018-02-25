class Solution {
public:
    /**
     * @param s: the IP string
     * @return: All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string &s) {
        // write your code here
        vector<string> v;
        vector<string> r;
        IpAddress(s, v, r, 0);

        return r;
    }
    void IpAddress(string &s, vector<string> &v, vector<string> &r, int start){
        if(start >= s.size()){
            ostringstream oss;
            if(v.size() == 4){
                for(int j = 0; j < 4; j++){
                    if(j == 0) oss << v[j];
                    else      oss << '.' << v[j];
                }
                r.push_back(oss.str());
            }
            return;
        }

        for(int i = start; i < start +3 && i < s.size(); i++){
            string ip = s.substr(start, i - start + 1);
            int num = stoi(ip);
            if(num <= MAXIP){
                v.push_back(ip);
                IpAddress(s, v, r, i + 1);
                v.pop_back(); 
            }
            if(num == 0) break;
        }
    }
    
private:
    const int MAXIP = 255;
};