/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

inline
bool compare(const pair<Point,int> &p1, const pair<Point, int> &p2){
    if(p1.second > p2.second) return true;
    else if(p1.second == p2.second){
        if(p1.first.x > p2.first.x) return true;
        else if(p1.first.x == p2.first.x) return p1.first.y > p2.first.y;
        else return false;
    }
    else return false;
}

class Solution {
public:
    /*
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> points, Point origin, int k) {
        // write your code here
        priority_queue<pair<Point,int>, vector<pair<Point,int>>, decltype(compare)*> heap(compare);
        for(int i = 0; i < points.size(); i++){
            cout << distance2(points[i], origin) << endl;
            heap.push(pair<Point,int>(points[i], distance2(points[i], origin)));
        }
        vector<Point> r;
        for(int i = 0; i < k && !heap.empty(); i++){
            r.push_back(heap.top().first);
            heap.pop();
        }
        return r;
    }
private:
    int distance2(Point p1, Point p2){
        return pow((p1.x-p2.x),2) + pow((p1.y - p2.y),2);
    }
};