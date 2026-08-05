# Move Zeroes

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.2 MB  
**Submitted:** 2026-08-05T14:35:07.202Z  

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
 for (int i =0 ; i<nums.size(); i++){
    if(nums[i] == 0){
        for(int j = i+1; j<nums.size(); j++){
            if(nums[j] != 0){
                swap(nums[i],nums[j]);

            }
        }
    }
 }
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/move-zeroes/)