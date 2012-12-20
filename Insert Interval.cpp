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
    Interval merge(Interval it1, Interval it2) {
        
        int start;
        it1.start < it2.start ? start = it1.start: start = it2.start;
        
        int end;
        it1.end > it2.end? end = it1.end: end = it2.end;
        
        
        
        return Interval(start,end); 
        
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> resultVector;
        bool done =false;
        
        for (int i=0;i<intervals.size();i++) {
            
            Interval readInter = intervals[i];
            
            if (readInter.end < newInterval.start)
                resultVector.push_back(readInter);
            else if (newInterval.end < readInter.start) {
                resultVector.push_back(newInterval);
                resultVector.insert(resultVector.end(),intervals.begin()+i,intervals.end());
                done  = true;
                break;
            } else {
                newInterval = merge (readInter,newInterval);
            }
            
        }
        
        if (!done) {
            resultVector.push_back(newInterval);
        }
        
        return resultVector;
    }
};
