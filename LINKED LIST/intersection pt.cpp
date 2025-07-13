https://leetcode.com/problems/intersection-of-two-linked-lists/

APPROACH-1) HASHMAP
class Solution {
public:
    unordered_map<ListNode*,int>mp;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*temp1=headA;
        ListNode*temp2=headB;
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        while(temp1!=NULL){
            mp[temp1];//node store
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            if(mp.find(temp2)!=mp.end()){
                return temp2;
            }
            temp2=temp2->next;
        }
        return NULL;
    }
};


APPROACH-2)LENGTH AND COMAPRE
class Solution {
public:
    int getDifference(ListNode* head1, ListNode* head2) {
        int len1 = 0, len2 = 0;
        while (head1 != NULL || head2 != NULL) {
            if (head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if (head2 != NULL) {
                ++len2; head2 = head2->next;
            }
        }
        return len1 - len2;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = getDifference(headA, headB);
        
        // as diff is h1-h2
        // so if h1-5,h2=7-->diff=-2)
        // here h2>h1; n2>n1
        while (diff < 0) {
            headB = headB->next;
            diff++;
        }
        // h1>h2
        while (diff > 0) {
            headA = headA->next;
            diff--;
        }

        // Traverse both together
        while (headA != NULL && headB != NULL) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};

APPROACH-3) NULL = END CHANGE

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA==NULL || headB==NULL) return NULL;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1 != temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2){
                return temp1;
            }
            if(temp1 == NULL){
                temp1=headB;
            }
            if(temp2 == NULL){
                temp2=headA;
            }
        }
        return temp1;
    }
};
