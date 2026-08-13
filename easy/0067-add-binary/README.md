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
**Runtime:** 3 ms (beats 18.24%)  
**Memory:** 9.9 MB (beats 22.88%)  
**Submitted:** 2026-08-13T16:16:22.804Z  

```cpp
class Solution {
public:

 int charToInt(char c) {
        return c - '0';
    }


    int getBit(const std::string& str, int index) {
        if (index >= 0) {
            return charToInt(str[index]);
        }
        return 0; // Return 0 if we run out of digits on the left
    }
    string addBinary(string a, string b) {
           string result = "";
        

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;


        while (i >= 0 || j >= 0 || carry > 0) {

            int sum = carry + getBit(a, i) + getBit(b, j);


            result += std::to_string(sum % 2);


            carry = sum / 2;


            i--;
            j--;
        }


reverse(result.begin(), result.end());

        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/add-binary/)