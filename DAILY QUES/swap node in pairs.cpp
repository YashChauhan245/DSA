https://leetcode.com/problems/swap-nodes-in-pairs/description/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* nextNode = head->next;
        head->next = swapPairs(head->next->next);
        nextNode->next = head;
        return nextNode;
    }
};
