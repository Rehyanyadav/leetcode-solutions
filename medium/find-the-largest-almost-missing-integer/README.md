# Find The Largest Almost Missing Integer

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** unknown  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-18T23:16:44.031Z  

```unknown
1class Solution {
2public:
3    bool isPalindrome(string s) {
4         int left = 0;
5        int right = s.length() - 1;
6
7        while (left < right) {
8            // Skip non-alphanumeric characters
9            if (!isalnum(s[left])) {
10                left++;
11            }
12            else if (!isalnum(s[right])) {
13                right--;
14            }
15            else {
16                // Compare after converting to lowercase
17                if (tolower(s[left]) != tolower(s[right])) {
18                    return false;
19                }
20                left++;
21                right--;
22            }
23        }
24        return true;
25    }
26};
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-largest-almost-missing-integer/)