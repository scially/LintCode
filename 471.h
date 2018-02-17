struct Words{
    string str;
    int    fre;
    Words(const string &s, int f): str(s), fre(f){}
};

bool less(const Words &w1, const Words &w2){
    if(w1.fre < w2.fre) return true;
    if(w1.fre == w2.fre) return w1.str > w2.str; // ?
    return false;
}

class Solution {
public:
    /*
     * @param words: an array of string
     * @param k: An integer
     * @return: an array of string
     */
    vector<string> topKFrequentWords(vector<string> &words, int k) {
        // write your code here
        vector<string> v;
        if(words.size() == 0) return v;
        map<string, int> m;
        for(int i = 0; i < words.size(); i++){
            if(m.find(words[i]) == m.end()){
                m[words[i]] = 1;
            }
            else
                m[words[i]]++;
        }
        
        priority_queue<Words, vector<Words>, decltype(::less)*> heap(::less);
        for(auto iter = m.begin(); iter != m.end(); iter++){
            heap.push(Words(iter->first, iter->second));
        }
        for(int i = 0; i < k && !heap.empty(); i++){
            v.push_back(heap.top().str);
            heap.pop();
        }
        return v;
    }
};