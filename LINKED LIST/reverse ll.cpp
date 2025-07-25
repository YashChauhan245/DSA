https://leetcode.com/problems/reverse-linked-list/description/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return head;
        }
        ListNode*last=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
};
