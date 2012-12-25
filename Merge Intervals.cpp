/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

/* sort takes O(nlogn), thus total time is O(nlogn)
 struct less_than_key
{
    inline bool operator() (const Interval& struct1, const Interval& struct2)
    {
        return (struct1.start < struct2.start);
    }
};

class Solution {
public:
    Interval merge(Interval a,Interval b) {
        int begin = a.start < b.start?a.start:b.start;
        int end = a.end > b.end?a.end:b.end;
        return Interval(begin,end);
        
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        if (intervals.empty()) return intervals;
        sort(intervals.begin(),intervals.end(),less_than_key());
        
        result.push_back(intervals[0]);
        for (int i=1;i<intervals.size();i++) {
            Interval aInterval = result.back();
            if (aInterval.end < intervals[i].start) {
                result.push_back(intervals[i]);
            }else {
                Interval mInterval = merge(aInterval,intervals[i]);
                result.pop_back();
                result.push_back(mInterval);
            }
        }
        
        return result;
    }
};
