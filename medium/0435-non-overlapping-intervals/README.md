# Non-overlapping Intervals

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 
Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.


Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.


Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


 
Constraints:


	1 <= intervals.length <= 105
	intervals[i].length == 2
	-5 * 104 <= starti < endi <= 5 * 104

## Solution

**Language:** C++  
**Runtime:** 43 ms (beats 67.43%)  
**Memory:** 94 MB (beats 39.13%)  
**Submitted:** 2026-08-20T17:59:36.701Z  

```cpp
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

```

---

[View on LeetCode](https://leetcode.com/problems/non-overlapping-intervals/)