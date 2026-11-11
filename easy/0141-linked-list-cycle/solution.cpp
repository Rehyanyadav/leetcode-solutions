class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Traverse while fast and fast->next are valid
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Moves 1 step
            fast = fast->next->next; // Moves 2 steps
            
            // If slow and fast meet, a cycle exists
            if (slow == fast) {
                return true;
            }
        }
        
        // If fast hits null, the list terminates (no cycle)
        return false;
    }
};