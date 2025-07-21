https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>minhp;
        for(int i=0;i<lists.size();i++){
            // checking head not null;
            if(lists[i])
                minhp.push({lists[i]->val,lists[i]});
        }
        ListNode*dummynode=new ListNode(-1);
        ListNode*temp=dummynode;
        while(!minhp.empty()){
            // storing min in it
            auto it=minhp.top();
            minhp.pop();
            // if its next is not null then push next data and node in heap
            if(it.second->next){
                minhp.push({it.second->next->val,it.second->next});
            }
            // storing it in dummy node and temp++
            temp->next=it.second;
            temp=temp->next;
        }
        // returing dummy next as we dont need -1
        return dummynode->next;
    }
};
