# Subarray Sum Equals K

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of integers `nums` and an integer `k`, return *the total number of subarrays whose sum equals to* `k`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

 

**Example 1:**

```
Input: nums = [1,1,1], k = 2
Output: 2

```

**Example 2:**

```
Input: nums = [1,2,3], k = 3
Output: 2

```

 

**Constraints:**

- 1 <= nums.length <= 2 * 104
- -1000 <= nums[i] <= 1000
- -107 <= k <= 107

## Solution

**Language:** C++  
**Runtime:** 44 ms (beats 51.68%)  
**Memory:** 45.5 MB (beats 38.40%)  
**Submitted:** 2026-09-27T11:00:46.801Z  

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int > map;
        int currentSum = 0;
        int count = 0;
        map[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            int rem = currentSum - k;

            if (map.find(rem) != map.end()) {
                count += map[rem];
            }

            map[currentSum]++;
        }
        
        return count;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subarray-sum-equals-k/)