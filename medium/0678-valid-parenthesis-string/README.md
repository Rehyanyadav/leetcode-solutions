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
**Runtime:** 2 ms (beats 12.80%)  
**Memory:** 8.4 MB (beats 16.93%)  
**Submitted:** 2026-08-24T22:36:34.601Z  

```cpp
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // Track the indices (positions) instead of characters
        stack<int> openSt;
        stack<int> starSt;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                openSt.push(i); // Store the index of '('
            } 
            else if (ch == '*') {
                starSt.push(i); // Store the index of '*'
            } 
            else { // Current character is ')'
                // First, try to match with a real opening bracket
                if (!openSt.empty()) {
                    openSt.pop();
                } 
                // If no '(' is available, try to use a '*' as an opening bracket
                else if (!starSt.empty()) {
                    starSt.pop();
                } 
                // If neither is available, it's invalid
                else {
                    return false;
                }
            }
        }

        // After the loop, match remaining '(' with '*' that appear AFTER them
        while (!openSt.empty() && !starSt.empty()) {
            // If the '(' appears AFTER the '*', the '*' cannot balance it (e.g., "*( ")
            if (openSt.top() > starSt.top()) {
                return false;
            }
            openSt.pop();
            starSt.pop();
        }

        // If openSt is empty, all open brackets found a match!
        return openSt.empty();
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/valid-parenthesis-string/)