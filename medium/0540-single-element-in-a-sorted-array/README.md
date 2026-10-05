# Single Element in a Sorted Array

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return *the single element that appears only once*.

Your solution must run in `O(log n)` time and `O(1)` space.

 

**Example 1:**

```
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

```

**Example 2:**

```
Input: nums = [3,3,7,7,10,11,11]
Output: 10

```

 

**Constraints:**

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 26.2 MB (beats 41.07%)  
**Submitted:** 2026-10-05T09:03:18.922Z  

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
     int n = nums.size();
 if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        
        int low = 1, high = n - 2;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if mid is the single element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            
            // Eliminate halves
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                low = mid + 1; // Search right
            } else {
                high = mid - 1; // Search left
            }
        }
        
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/single-element-in-a-sorted-array/)