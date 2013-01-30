/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        while (!intervals.empty()){
            Interval current = intervals.front();
            intervals.erase(intervals.begin());
            if (newInterval.end < current.start){
                result.push_back(newInterval);
                result.push_back(current);
                result.insert(result.end(),intervals.begin(),intervals.end());
                return result;
            } else if (newInterval.start > current.end){
                result.push_back(current);
            } else {
                int new_start = min(newInterval.start,current.start);
                int new_end = max(newInterval.end,current.end);
                newInterval.start = new_start;
                newInterval.end = new_end;
            }
        }
        result.push_back(newInterval);
        return result;
    }
};
