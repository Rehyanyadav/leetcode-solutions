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
**Runtime:** 0 ms  
**Memory:** 8.3 MB  
**Submitted:** 2026-08-30T15:57:59.846Z  

```cpp
for(int i =1; i<intervals.size(); i++){
    if(intervals[i][0] >= last_end_time){


      int last_end_time = intervals[0][1];


      int removed_count = 0;
      sort (intervals.begin(), intervals.end(),compare);

}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      if(intervals.empty()) return 0;
    return a[1]< b[1];

public:
static bool compare (vector<int> & a, vector<int> & b){
class Solution {

```

---

[View on LeetCode](https://leetcode.com/problems/non-overlapping-intervals/)