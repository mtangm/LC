/*
 *Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
 *
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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        for (const auto& v : intervals)
        {
            result = insert(result, v);
        }
        
        return result;
    }
    
    // The following api is copied from my solution of "insert interval"
    // my solution refered to the book of EPI
    //
    // note that intervals can be empty vector
    //
    
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        
        int i=0;
        while (i < intervals.size() && intervals[i].end < newInterval.start)
        {
            res.push_back(intervals[i++]);
        }
        
        // overlaps
        while (i<intervals.size() && intervals[i].start <= newInterval.end)
        {
            newInterval.start=min(intervals[i].start, newInterval.start);
            newInterval.end=max(intervals[i].end, newInterval.end);
            i++;
        }
        
        res.push_back(newInterval);
        
        // add the rest non-overlapped elements
        while (i<intervals.size())
        {
            res.push_back(intervals[i++]);
        }
        
        return res;
    }
};
