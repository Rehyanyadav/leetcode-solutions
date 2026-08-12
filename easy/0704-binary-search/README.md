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
**Memory:** 8.3 MB  
**Submitted:** 2026-08-12T09:45:10.058Z  

```cpp
        }
            return mid;
            if(nums[mid]>target)
            return mid-1;
            else
            low = mid+1;

            if(nums[mid] == target)
        return -1;

    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/binary-search/)