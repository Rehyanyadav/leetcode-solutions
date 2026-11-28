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
   ListNode* getKthNode(ListNode* start , int k ){


    ListNode* curr = start;
    for(int i =0 ; i< k  && curr != nullptr;i++){
        curr = curr->next;

    }
    return curr;

   }

   ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr != nullptr){
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

    }
    return prev;

   }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head == nullptr || k<= 1){
        return head;

       }

       ListNode dummy(0);
       dummy.next = head;
       ListNode* prevGroupTail = &dummy;

        while (true) {
            ListNode* kthNode = getKthNode(prevGroupTail, k);
            if (kthNode == nullptr) {
               
                break;
            }

            ListNode* nextGroupHead = kthNode->next;
            kthNode->next = nullptr; 

            ListNode* groupStart = prevGroupTail->next;
            ListNode* newGroupHead = reverseList(groupStart);

            prevGroupTail->next = newGroupHead;
            groupStart->next = nextGroupHead;

    //  
            prevGroupTail = groupStart;
        }

        return dummy.next;
     
    }
};
