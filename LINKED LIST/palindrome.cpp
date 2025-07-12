https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tail = reverseList(slow);
        prev->next = NULL; //both ll separated
        
        while(tail != NULL && head != NULL) {
            if(tail->val != head->val) {
                return false;
            }

            tail = tail->next;
            head = head->next;
        }

        return true;
    }
};
