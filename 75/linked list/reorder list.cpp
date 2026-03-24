https://leetcode.com/problems/reorder-list/description/

/**
 * FIND MIDDLE 
 * REVERSE 2ND HALF(MID+1,E)
 * MERGE USING 2 POINTER   
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* node) {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* last = reverseLL(node->next);
        node->next->next = node;
        node->next = NULL;
        return last;
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;

        //find middle 
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse 2nd half 
        ListNode* revHalf = reverseLL(slow);
        
        ListNode* curr = head;
      
       //merging 
        while(revHalf->next) {
            ListNode* tempFront = curr->next;    //storing curr next
            curr->next          = revHalf;       //joining curr to rev(lat node)   
            ListNode* tempBack  = revHalf->next; //storing 2nd last node
            revHalf->next       = tempFront;     //joining last node to 2nd node (tempFront)
            revHalf             = tempBack;      //again updating curr 
            curr                = tempFront;     //again updating rev
        }
    }
};
