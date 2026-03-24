https://leetcode.com/problems/merge-k-sorted-lists/description/

t.c->O(log(k) * k * n)

/*APPROACH->divide into 2 list and merge 
 *Step-1)use merge 2 lists apporach 
 *Step-2)also assume if {l1,l2,l3,l4,l5}->so merge ony by one like 1st (l1& l2_ then there (merge,l3) then there (merge,l4) and so on
 *Step-3)instead use merge sort --->divide and merge when 2 listes are there only like (l1,l2) merge of \
 (l1-l2,l3) and (l4,l5)
*/
class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        if(l1->val <= l2->val) {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
        
        return NULL;
    }
    
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if(start == end)
            return lists[start];       
        if(start > end)
            return NULL;
        
        int mid = start + (end-start)/2;
        
        ListNode* l1 = partitionAndMerge(start, mid, lists);
        ListNode* l2 = partitionAndMerge(mid+1, end, lists);
        
        return mergeTwoSortedLists(l1, l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {      
        int n = lists.size();      
        if(n == 0)
            return NULL;       
        return partitionAndMerge(0, n-1, lists);
        
    }
};
