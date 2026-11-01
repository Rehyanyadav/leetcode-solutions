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