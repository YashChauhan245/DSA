https://leetcode.com/problems/reverse-linked-list/

/**APPR0ACH
 1)go to last element
 2)store last element
 3)now we are at second last elemnent so reverse it by head->next->next=head;
 4)erase the old root
 5)return last stored element as its our new head
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return head;
        }
        ListNode*last=reverseList(head->next);//go to last element
        head->next->next=head; //create new route
        head->next=NULL; //erase old route
        return last;  //return last element as its our new head
    }
};
