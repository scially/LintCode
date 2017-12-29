/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */


class Solution {
public:
    /*
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), compare);
        // 在这里添加一个[+∞，+∞]区间，这样我们就可以将整个循环统一起来
        // 无论最后一个区间是不是一个新的独立区间，当遇到[+∞，+∞]时都会被
        // 分离开来，而我们的循环恰好是到n-1终止。
        intervals.push_back(Interval(INT_MAX, INT_MAX));
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 0; i < intervals.size()-1; i++){
            end = max(end, intervals[i].end);
            if(end < intervals[i+1].start){
                ret.push_back(Interval(start, end));
                start = intervals[i+1].start;
                end = intervals[i+1].end;
            }
        }
        return ret;
    }
    static bool compare(const Interval &l, const Interval &r){
        return l.start < r.start;
    }
};