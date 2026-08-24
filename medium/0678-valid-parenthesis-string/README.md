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
**Submitted:** 2026-08-24T22:23:43.015Z  

```cpp
             char topElement = st.top();
             st.pop();


             //* check if pop brackets are matching the current closing brackets
                 if ((ch == ')' && topElement != '(') ||
        
            }
        }

        
                (ch == '}' && topElement != '{') ||
                (ch == ']' && topElement != '[')) {
                return false;
            }
      return st.empty();

    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/valid-parenthesis-string/)