https://leetcode.com/problems/rotate-list/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;

        // Step 1: Calculate the length of the list
        ListNode* temp = head;
        int length = 1;
        while (temp->next != NULL) {
            ++length;
            temp = temp->next;
        }

        // Step 2: Connect last node to the head (make it circular)
        temp->next = head;

        // Step 3: Find the new tail after (length - k % length) steps
        k %= length;
        int stepsToNewTail = length - k;

        while (stepsToNewTail--) {
            temp = temp->next;
        }

        // Step 4: Break the cycle and set the new head
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
