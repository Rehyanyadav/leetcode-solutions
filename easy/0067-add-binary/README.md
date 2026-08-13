# Add Binary

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two binary strings a and b, return their sum as a binary string.

 
Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

 
Constraints:


	1 <= a.length, b.length <= 104
	a and b consist only of '0' or '1' characters.
	Each string does not contain leading zeros except for the zero itself.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.8 MB  
**Submitted:** 2026-08-13T16:14:21.288Z  

```cpp
            }

            // Append the remainder bit (carry % 2) converted back to a character
            result += (carry % 2) + '0'; 
            
            // Calculate the new carry (carry / 2) for the next column
            carry /= 2;                  
        }

        // The result is built backwards, so we flip it right-side up
        std::reverse(result.begin(), result.end());
        
        return result;

    }

```

---

[View on LeetCode](https://leetcode.com/problems/add-binary/)