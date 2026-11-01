# Reverse Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.

 

**Example 1:**

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

```

**Example 2:**

```
Input: head = [1,2]
Output: [2,1]

```

**Example 3:**

```
Input: head = []
Output: []

```

 

**Constraints:**

- The number of nodes in the list is the range [0, 5000].
- -5000 <= Node.val <= 5000

 

**Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 13.6 MB (beats 12.73%)  
**Submitted:** 2026-11-01T16:32:10.746Z  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         //base case if list is empty  already reversed
         if(head == nullptr || head-> next == nullptr){
            return head;
         }
// recursively reverse the rest of the list 
ListNode* newdHead = reverseList(head-> next);

//making next node point back to curr node
head->next->next = head;

//disconnect original forward link to avoid cycles
head-> next = nullptr;


return newdHead;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-linked-list/)