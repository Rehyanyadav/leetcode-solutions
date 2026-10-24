# Subarrays with K Different Integers

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer array `nums` and an integer `k`, return *the number of **good subarrays** of *`nums`.

A **good array** is an array where the number of different integers in that array is exactly `k`.

- For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

A **subarray** is a **contiguous** part of an array.

 

**Example 1:**

```
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

```

**Example 2:**

```
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

```

 

**Constraints:**

- 1 <= nums.length <= 2 * 104
- 1 <= nums[i], k <= nums.length

## Solution

**Language:** C++  
**Runtime:** 57 ms (beats 86.78%)  
**Memory:** 53.4 MB (beats 87.03%)  
**Submitted:** 2026-10-24T14:32:34.054Z  

```cpp
class Solution {
private:
    int atMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int n = nums.size();
        int l = 0, totalCount = 0;
        unordered_map<int, int> freqMap;
        
        for (int r = 0; r < n; r++) {
            if (freqMap[nums[r]] == 0) {
                k--; 
            }
            freqMap[nums[r]]++;
            while (k < 0) {
                freqMap[nums[l]]--;
                if (freqMap[nums[l]] == 0) {
                    k++; 
                }
                l++;
            }

            totalCount += (r - l + 1);
        }
        
        return totalCount;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subarrays-with-k-different-integers/)