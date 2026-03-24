https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;

        // Step 1: count size
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        // Step 2: if head needs to be deleted
        if (n == size) {
            return head->next;
        }
        // Step 3: go to (size - n - 1) node
        temp = head;
        for (int i = 1; i < size - n; i++) {  
            temp = temp->next;  //reached at index 1 less than target
        }
        // Step 4: delete node
        temp->next = temp->next->next;

        return head;
    }
};
