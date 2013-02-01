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


/* 
   another solution , using mergesort like algorithm, also takes O(nlogn)
*/
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
    vector<Interval> merge_interval(vector<Interval> &left,vector<Interval> &right){
        vector<Interval> result;
     while (!left.empty() || !right.empty()){
            
            Interval l1,r1;
            if (result.empty()) {
                l1 = left.front();
                r1 = right.front();
                left.erase(left.begin());
                right.erase(right.begin());
            }else {
                l1 = result.back();
                result.pop_back();
                
                if (!left.empty() && !right.empty()) {
                    if (left.front().start < right.front().start){
                        r1 = left.front();
                        left.erase(left.begin());
                    }else {
                        r1 = right.front();
                        right.erase(right.begin());
                    }
                } else if (left.empty() && !right.empty()) {
                       r1 = right.front();
                       right.erase(right.begin());
                } else if (right.empty() && !left.empty()) {
                        r1 = left.front();
                        left.erase(left.begin());
                } else {
                    //both empty
                    break;
                }
            }
            if (l1.end < r1.start) {
                result.push_back(l1);
                result.push_back(r1);
            } else if ( r1.end< l1.start) {
                result.push_back(r1);
                result.push_back(l1);
            } else {
                int ms = min(l1.start,r1.start);
                int me = max(l1.end,r1.end);
                Interval tmp(ms,me);
                result.push_back(tmp);
            }
            
        }

        return result;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.empty()) return intervals;
        if (intervals.size() == 1) return intervals;
        int mid = intervals.size()/2;
        vector<Interval> leftpart = vector<Interval> (intervals.begin(),intervals.begin()+mid);
        vector<Interval> leftResult = merge(leftpart);
        vector<Interval> rightpart = vector<Interval> (intervals.begin()+mid,intervals.end());
        vector<Interval> rightResult = merge(rightpart);
        return merge_interval(leftResult,rightResult);
    }
};
