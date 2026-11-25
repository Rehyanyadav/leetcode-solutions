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
    ListNode* deleteMiddle(ListNode* head) {
        // If list is empty or has only 1 node, deleting middle leaves empty list
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move fast 2x and slow 1x while tracking the node right before slow
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Unlink the middle node (slow) by connecting prev directly to slow->next
        prev->next = slow->next;
        delete slow;
        
        return head;
    }
};