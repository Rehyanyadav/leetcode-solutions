# Max Consecutive Ones

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a binary array nums, return the maximum number of consecutive 1's in the array.

 
Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.


Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2


 
Constraints:


	1 <= nums.length <= 105
	nums[i] is either 0 or 1.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.2 MB  
**Submitted:** 2026-09-05T05:23:46.532Z  

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxi = max(maxi, count); // Is my current streak a new record?
            } else {
                count = 0; // Streak broken, reset to 0
            }
        }
        
        return maxi;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/max-consecutive-ones/)