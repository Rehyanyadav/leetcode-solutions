class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //* greedy approach 
        //* Activity selection 
        
        if (intervals.empty()) {
            return 0;
        }

        // Sort intervals by their end times
        // Using a custom lambda function ensures we prioritize the earliest end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count_non_overlapping = 1;
        int last_end = intervals[0][1];

        // Greedily pick intervals that start after or when the last one ends
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= last_end) {
                count_non_overlapping++;
                last_end = intervals[i][1];
            }
        }

        // Minimum removals needed = Total intervals minus maximum compatible intervals
        return intervals.size() - count_non_overlapping;
    }
};
