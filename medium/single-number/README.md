# Single Number

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.2 MB  
**Submitted:** 2026-09-01T23:19:02.539Z  

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int ans = 0;

    for (const int num : nums)
      ans ^= num;

    return ans;
  }
   
    
};

```

---

[View on LeetCode](https://leetcode.com/problems/single-number/)