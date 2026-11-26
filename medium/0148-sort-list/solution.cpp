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