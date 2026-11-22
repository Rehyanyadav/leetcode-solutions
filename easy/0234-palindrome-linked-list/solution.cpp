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