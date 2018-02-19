struct Node{
    int val, index;
    Node(int val, int index){
        this->val = val;
        this->index = index;
    }
};

inline 
bool compare(const Node &l, const Node &r){
    return l.val < r.val;
}

class Solution {
    using Heap = priority_queue<Node, vector<Node>, decltype(::compare)*>;
public:
    /**
     * @param rating: the rating of the movies
     * @param G: the realtionship of movies
     * @param S: the begin movie
     * @param K: top K rating 
     * @return: the top k largest rating moive which contact with S
     */
    vector<int> topKMovie(vector<int> &rating, vector<vector<int>> &G, int S, int K) {
        // Write your code here
        Heap heap(::compare); // don't forget
        vector<bool> visited(rating.size(), false);
        relations(rating, G, visited, S, S, heap);
        vector<int> r;
		for (int i = 0; i < K && !heap.empty(); i++){
			r.push_back(heap.top().index);
			heap.pop();
		}
		return r;
    }

private:
    // dfs
    void relations(vector<int> &rating, vector<vector<int>> &G, vector<bool> &v,
                    int S, int target, Heap &heap){
        if(v[target]) return;
        v[target] = true;
        
        if(S != target){
            Node node(rating[target], target);
            heap.push(node);
        }
        for(int i = 0; i < G[target].size(); i++){
            relations(rating, G, v, S, G[target][i], heap);
        }
    }
};