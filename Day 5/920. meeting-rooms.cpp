/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// C++ Custom Sort

bool comp(Interval &first, Interval &second) {
    return first.start < second.start;
}

class Solution {
   public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        sort(intervals.begin(), intervals.end(), comp);
        int end = 0;
        for (auto curr : intervals) {
            if (end > curr.start) return false;
            end = curr.end;
        }
        return true;
    }
};