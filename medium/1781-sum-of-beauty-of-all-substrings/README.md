# Sum of Beauty of All Substrings

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

The **beauty** of a string is the difference in frequencies between the most frequent and least frequent characters.

- For example, the beauty of "abaacc" is 3 - 1 = 2.

Given a string `s`, return *the sum of **beauty** of all of its substrings.*

 

**Example 1:**

```
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
```

**Example 2:**

```
Input: s = "aabcbaa"
Output: 17

```

 

**Constraints:**

- 1 <= s.length <= 500
- s consists of only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 125 ms (beats 28.47%)  
**Memory:** 11.4 MB (beats 42.54%)  
**Submitted:** 2026-10-27T09:50:15.020Z  

```cpp
class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.length();
        

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0); 
            

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++; 
                
                int maxFreq = 0;
                int minFreq = INT_MAX;
                

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                

                totalBeauty += (maxFreq - minFreq);
            }
        }
        
        return totalBeauty;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)