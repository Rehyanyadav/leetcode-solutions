# Move Zeroes

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.4 MB  
**Submitted:** 2026-08-05T14:46:56.513Z  

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         //* efficient solution 
         int count = 0;
         for(int i =0; i<nums.size(); i++){
            if(nums[i] != 0){
         }
                swap(nums[i] , nums[count]);
            }
    }
                count ++;
                
};

```

---

[View on LeetCode](https://leetcode.com/problems/move-zeroes/)