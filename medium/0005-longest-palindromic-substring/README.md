# Longest Palindromic Substring

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, return *the longest* *palindromic* *substring* in `s`.

 

**Example 1:**

```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

```

**Example 2:**

```
Input: s = "cbbd"
Output: "bb"

```

 

**Constraints:**

- 1 <= s.length <= 1000
- s consist of only digits and English letters.

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 88.07%)  
**Memory:** 9.4 MB (beats 74.38%)  
**Submitted:** 2026-10-26T10:53:14.107Z  

```cpp

class Solution {
private:
    int expandAroundCenter(const string& s, int left, int right) {
        int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        int start = 0, maxLength = 1;

        for (int i = 0; i < n; i++) {
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i + 1);

            int len = max(odd, even);

            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/longest-palindromic-substring/)