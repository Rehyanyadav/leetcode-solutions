# Pascal's Triangle

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

 

**Example 1:**

```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

```

**Example 2:**

```
Input: numRows = 1
Output: [[1]]

```

 

**Constraints:**

- 1 <= numRows <= 30

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.7 MB (beats 61.67%)  
**Submitted:** 2026-09-15T03:15:34.658Z  

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
for(int i =0; i<numRows; i++){
vector<int>temp (i+1 ,1);
for(int j = 1; j<i; j++){
    temp[j] = ans[i-1][i-j]+ans[i-1][j];

}
ans.push_back(temp);


}
return ans;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/pascals-triangle/)