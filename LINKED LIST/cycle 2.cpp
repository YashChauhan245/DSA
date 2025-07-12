https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*p=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(slow!=p){
                    p=p->next;
                    slow=slow->next;
                }
                return p;
            }
        }
        return NULL;
        
    }
};
