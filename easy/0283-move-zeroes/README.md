# Move Zeroes

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]

 
Constraints:


	1 <= nums.length <= 104
	-231 <= nums[i] <= 231 - 1


 
Follow up: Could you minimize the total number of operations done?

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.2 MB  
**Submitted:** 2026-09-04T11:32:17.056Z  

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
          //* efficient solution 
         int count = 0;
         for(int i =0; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i] , nums[count]);
                count ++;
                
            }
         }
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/move-zeroes/)