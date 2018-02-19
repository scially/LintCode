struct TrieNode{
    bool endword;
    TrieNode *node[26];
    TrieNode( bool end = false) 
            :endword(end){
        for(int i = 0; i < 26; i++)
            node[i] = nullptr;
    }
};

class Trie {
public:
    Trie() {
        // do intialization if necessary
        root = new TrieNode;
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here
        TrieNode *dummy = root;
        for(int i = 0; i < word.length(); i++){
            int j = word[i] - 'a';
            if(dummy->node[j] == nullptr){
                dummy->node[j] = new TrieNode;
            }
            dummy = dummy->node[j];
        }
        dummy->endword = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here
        TrieNode *dummy = root;
        for(int i = 0; i < word.length(); i++){
            int j = word[i] - 'a';
            if(dummy->node[j] == nullptr)
                return false;
            dummy = dummy->node[j];
        }
        return dummy->endword;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here
        TrieNode *dummy = root;
        for(int i = 0; i < prefix.length(); i++){
            int j = prefix[i] - 'a';
            if(dummy->node[j] == nullptr)
                return false;
            dummy = dummy->node[j];
        }
        return true;
    }
private:
    TrieNode *root;
};