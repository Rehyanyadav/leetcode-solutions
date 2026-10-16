# Isomorphic Strings

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two strings `s` and `t`, *determine if they are isomorphic*.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

**Example 1:**

**Input:** s = "egg", t = "add"

**Output:** true

**Explanation:**

The strings `s` and `t` can be made identical by:

- Mapping 'e' to 'a'.
- Mapping 'g' to 'd'.

**Example 2:**

**Input:** s = "f11", t = "b23"

**Output:** false

**Explanation:**

The strings `s` and `t` can not be made identical as `'1'` needs to be mapped to both `'2'` and `'3'`.

**Example 3:**

**Input:** s = "paper", t = "title"

**Output:** true

 

**Constraints:**

- 1 <= s.length <= 5 * 104
- t.length == s.length
- s and t consist of any valid ascii character.

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 51.46%)  
**Memory:** 9.4 MB (beats 27.77%)  
**Submitted:** 2026-10-16T17:00:28.814Z  

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mapS(256, 0);
        vector<int> mapT(256, 0);
        
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            // If mappings exist, check if they match our current characters
            if (mapS[c1] != 0 && mapS[c1] != c2) return false;
            if (mapT[c2] != 0 && mapT[c2] != c1) return false;
            
            // Establish the bidirectional mapping
            mapS[c1] = c2;
            mapT[c2] = c1;
        }
        
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/isomorphic-strings/)