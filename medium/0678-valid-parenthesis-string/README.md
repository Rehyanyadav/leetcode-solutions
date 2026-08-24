# Valid Parenthesis String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:


	Any left parenthesis '(' must have a corresponding right parenthesis ')'.
	Any right parenthesis ')' must have a corresponding left parenthesis '('.
	Left parenthesis '(' must go before the corresponding right parenthesis ')'.
	'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


 
Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "(*)"
Output: true
Example 3:
Input: s = "(*))"
Output: true

 
Constraints:


	1 <= s.length <= 100
	s[i] is '(', ')' or '*'.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 7.9 MB (beats 93.14%)  
**Submitted:** 2026-08-24T22:41:16.661Z  

```cpp
class Solution {
public:
    bool checkValidString(string s) {
         int min_val = 0; // Tracks the minimum possible open brackets '('
        int max_val = 0; // Tracks the maximum possible open brackets '('

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                min_val++;
                max_val++;
            } 
            else if (s[i] == ')') {
                min_val--;
                max_val--;
            } 
            else { // It is an asterisk '*'
                min_val--; // If '*' acts as ')'
                max_val++; // If '*' acts as '('
            }

            // At any point, if max_val drops below 0, there are too many closing brackets
            if (max_val < 0) {
                return false;
            }

            // min_val cannot be negative; reset it to 0 (assume '*' acts as empty string instead)
            if (min_val < 0) {
                min_val = 0;
            }
        }

        // If min_val is 0, we can successfully close all brackets
        return (min_val == 0);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-parenthesis-string/)