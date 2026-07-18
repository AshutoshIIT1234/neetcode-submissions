class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort by end time
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        
        int count = 0; // intervals to remove
        int lastEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < lastEnd) {
                // Overlaps with the last kept interval -> remove this one
                count++;
            } else {
                // No overlap, keep this interval, update lastEnd
                lastEnd = intervals[i][1];
            }
        }
        
        return count;
    }
};