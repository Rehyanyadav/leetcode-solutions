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
**Runtime:** 0 ms  
**Memory:** 7.8 MB  
**Submitted:** 2026-08-24T22:25:54.737Z  

```cpp
            }
        }

        // After the loop, match remaining '(' with '*' that appear AFTER them
        while (!openSt.empty() && !starSt.empty()) {
            // If the '(' appears AFTER the '*', the '*' cannot balance it (e.g., "*( ")
            if (openSt.top() > starSt.top()) {
                return false;
            }
            openSt.pop();
            starSt.pop();
        }

        // If openSt is empty, all open brackets found a match!
        return openSt.empty();
    }
};


```

---

[View on LeetCode](https://leetcode.com/problems/valid-parenthesis-string/)