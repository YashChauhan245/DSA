https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {

            // Duplicate group found
            if (curr->next != nullptr && curr->val == curr->next->val) {

                // Skip all nodes with the same value
                while (curr->next != nullptr && curr->val == curr->next->val) {
                    curr = curr->next;
                }

                // Skip the entire duplicate group
                prev->next = curr->next;
            }
            else {
                // curr is unique, so move prev
                prev = prev->next;
            }

            // Move curr
            curr = curr->next;
        }

        return dummy->next;
    }
};
