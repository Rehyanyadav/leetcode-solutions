# Single Number

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 20.8 MB (beats 13.30%)  
**Submitted:** 2026-09-01T23:19:07.344Z  

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int ans = 0;

    for (const int num : nums)
      ans ^= num;

    return ans;
  }
   
    
};
```

---

[View on LeetCode](https://leetcode.com/problems/single-number/)