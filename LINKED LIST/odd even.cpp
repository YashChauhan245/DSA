https://leetcode.com/problems/odd-even-linked-list/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {    
        if(head==NULL ){
            return NULL;
        }
        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*evenstart=head->next;

        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenstart; 
        return head;   
    }
};
