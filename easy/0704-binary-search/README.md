# Binary Search

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 
Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4


Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1


 
Constraints:


	1 <= nums.length <= 104
	-104 < nums[i], target < 104
	All the integers in nums are unique.
	nums is sorted in ascending order.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.4 MB  
**Submitted:** 2026-08-13T12:13:23.859Z  

```cpp
        if (nums[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (nums[mid] < target)
        // Check if x is present at mid

        int mid = low + (high - low) / 2;
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }


```

---

[View on LeetCode](https://leetcode.com/problems/binary-search/)