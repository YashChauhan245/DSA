https://leetcode.com/problems/merge-two-sorted-lists/description/

/**APPROACH
  1)take result node 
  2)comapre l1 and l2 ->pick the smallest and assign that in result
  3)so now result have the smalest node ->sned merge recursion call for remaining nodes
  4)return result 
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* result;
        if(l1->val < l2->val) {
            result = l1;
            result->next = mergeTwoLists(result->next, l2);
        } else {
            result = l2;
            result->next = mergeTwoLists(l1, result->next);
        }
        return result;
    }
};
