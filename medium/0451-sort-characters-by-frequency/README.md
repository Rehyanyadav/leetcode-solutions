# Sort Characters By Frequency

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, sort it in **decreasing order** based on the **frequency** of the characters. The **frequency** of a character is the number of times it appears in the string.

Return *the sorted string*. If there are multiple answers, return *any of them*.

 

**Example 1:**

```
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

```

**Example 2:**

```
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

```

**Example 3:**

```
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

```

 

**Constraints:**

- 1 <= s.length <= 5 * 105
- s consists of uppercase and lowercase English letters and digits.

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 20.29%)  
**Memory:** 14.1 MB (beats 11.78%)  
**Submitted:** 2026-10-20T11:25:55.617Z  

```cpp
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        int maxFreq = 0;
        for (char c : s) {
            freqMap[c]++;
            maxFreq = max(maxFreq, freqMap[c]);
        }
        

        vector<string> buckets(maxFreq + 1, "");
        for (auto& pair : freqMap) {
            char c = pair.first;
            int freq = pair.second;
            buckets[freq].append(freq, c); 
        }

        string result = "";
        for (int i = maxFreq; i > 0; i--) {
            if (!buckets[i].empty()) {
                result += buckets[i];
            }
        }
        
        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sort-characters-by-frequency/)