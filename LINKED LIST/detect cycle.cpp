https://leetcode.com/problems/linked-list-cycle/submissions/1695008877/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode* slow = head;       
        ListNode* fast = head;   //not head bcz ist condn me hi true de dega 

        while (fast != nullptr  && fast->next != nullptr) {
            slow = slow->next;        
            fast = fast->next->next;
            if (slow == fast){
                return true; 
            }
        }
        return false;
    }
};
