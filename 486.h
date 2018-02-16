#define LEFTNODE(i)   ((i) * 2 + 1)
#define RIGHTNODE(i)  ((i) * 2 + 2)
#define PARENTNODE(i) ((i) > 0 ? (((i) - 1) / 2) : -1)

struct MinHeapNode{
    int val;
    int i, j; // 所在数组索引，所在数组位置索引
    MinHeapNode(int v, int i, int j){
        this->val = v;
        this->i   = i;
        this->j   = j;
    }
    MinHeapNode() :MinHeapNode(INT_MAX, -1, -1)
    {}
};

// class MinHeap
class MinHeap{
public:
    MinHeap(const vector<MinHeapNode> &arr){
        //copy(arr.begin(), arr.end(), back_inserter(array)); 
        count = arr.size();
        array = new MinHeapNode[count];
        copy(arr.begin(), arr.end(), array); 
        int i = PARENTNODE(count - 1);
        while(i >= 0){
            shiftDown(i);
            i--;
        }
    }
    ~MinHeap(){
        if(array) delete[] array;
    }
    int size() const { return count; }
    bool empty() const { return count == 0; }
    MinHeapNode extractMin(){
        MinHeapNode r = array[0];
        swap(array[0], array[count-1]);
        --count;
        shiftDown(0);
        return r;
    }
    
    void insert(const MinHeapNode &r){
        array[count] = r;
        ++count;
        shiftUp(count - 1);
    }
private:
    MinHeapNode* array;
    int count;
    void shiftDown(int i){
        while(LEFTNODE(i) < count){
            int j = LEFTNODE(i);
            if(RIGHTNODE(i) < count && array[j].val > array[RIGHTNODE(i)].val){
                j = RIGHTNODE(i);
            }
            if(array[i].val < array[j].val) break;  // !!
            swap(array[i], array[j]);
            i = j;
        }
    }
    void shiftUp(int i){
        while(i > 0 && array[PARENTNODE(i)].val > array[i].val){
            swap(array[PARENTNODE(i)], array[i]);
            i = PARENTNODE(i);
        }
    }
};

class Solution {
public:
    /*
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
        vector<MinHeapNode> array;
        vector<int> v;
        for(int i = 0; i < arrays.size(); i++){
            if(arrays[i].size() == 0) continue;
            
            MinHeapNode m(arrays[i][0], i, 0);
            array.push_back(m);
        }
        if(array.size() == 0) return v;
        MinHeap heap(array);
        while(!heap.empty()){
            MinHeapNode node = heap.extractMin();
            v.push_back(node.val);
            if(++node.j < arrays[node.i].size()){
                node.val = arrays[node.i][node.j];
                heap.insert(node);
            }
        }
        return v;
    }
};