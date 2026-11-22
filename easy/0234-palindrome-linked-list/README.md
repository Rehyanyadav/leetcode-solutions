# Palindrome Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `head` of a singly linked list, return `true`* if it is a **palindrome** or *`false`* otherwise*.

 

**Example 1:**

```
Input: head = [1,2,2,1]
Output: true

```

**Example 2:**

```
Input: head = [1,2]
Output: false

```

 

**Constraints:**

- The number of nodes in the list is in the range [1, 105].
- 0 <= Node.val <= 9

 

**Follow up:** Could you do it in `O(n)` time and `O(1)` space?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 121.7 MB (beats 43.90%)  
**Submitted:** 2026-11-22T06:33:26.921Z  

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


private: 
 ListNode* reverseList(ListNode* head){
     ListNode* prev = nullptr;
     ListNode* curr = head;

     while(curr != nullptr){
        ListNode* nextNode = curr-> next;
        curr->next = prev;
        prev  = curr;
        curr = nextNode;

     }

     return prev;

 }

public:
    bool isPalindrome(ListNode* head) {
     if(head == nullptr || head -> next == nullptr){
        return true ;

     }  

     ListNode* slow = head;
     ListNode* fast = head;
     while(fast != nullptr && fast -> next != nullptr) {
        slow = slow->next;
        fast = fast ->next -> next;

     }
     // reverse the second half of the LL 

     ListNode* secondHalfHead = reverseList(slow);
     ListNode* firstHalfcurr = head;
     ListNode* secondHalfcurr = secondHalfHead;

// compare first half and reversed second half 

bool palindrome = true;

while(secondHalfcurr != nullptr){
    if(firstHalfcurr ->val != secondHalfcurr -> val){
        palindrome = false;
        break;

    }
    firstHalfcurr = firstHalfcurr ->next;
    secondHalfcurr = secondHalfcurr->next;

}

reverseList(secondHalfHead);
return palindrome;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindrome-linked-list/)