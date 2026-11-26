# Sort List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `head` of a linked list, return *the list after sorting it in **ascending order***.

 

**Example 1:**

```
Input: head = [4,2,1,3]
Output: [1,2,3,4]

```

**Example 2:**

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

```

**Example 3:**

```
Input: head = []
Output: []

```

 

**Constraints:**

- The number of nodes in the list is in the range [0, 5 * 104].
- -105 <= Node.val <= 105

 

**Follow up:** Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?

## Solution

**Language:** C++  
**Runtime:** 12 ms (beats 77.04%)  
**Memory:** 57 MB (beats 70.74%)  
**Submitted:** 2026-11-26T06:59:08.244Z  

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

    private :
           ListNode* getMiddle(ListNode* head ){
              ListNode* slow = head;
              ListNode* fast = head->next;
              while( fast != nullptr  && fast->next != nullptr){
                slow = slow ->next;
                fast = fast ->next ->next;

              }
              return slow;


    }



//   here we merge two sorted linked list into one sorted list 
    ListNode* merge(ListNode* l1 , ListNode* l2){
   ListNode dummy(0);
   ListNode* tail = &dummy;

   while(l1 != nullptr && l2  != nullptr){
    if(l1->val <= l2->val){
        tail->next = l1;
        l1 = l1->next;
        
    }else{
        tail ->next =l2;
        l2 = l2 ->next;

    }
    tail = tail->next;

   }
   tail->next = (l1 != nullptr) ?  l1 : l2;
   return dummy.next;

    }
public:
    ListNode* sortList(ListNode* head) {
   if(head == nullptr || head->next == nullptr)     {
return head;

   }

//split the list into 2 half 

   ListNode* mid = getMiddle(head);
  ListNode* rightHead = mid->next;
  mid-> next = nullptr;  // break the link between left and right half 


  // sorting both half recursively
  ListNode* leftSorted = sortList(head);
  ListNode* rightSorted = sortList(rightHead);


//merge the sorted half 
  return merge(leftSorted , rightSorted);

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sort-list/)