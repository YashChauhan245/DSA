https://leetcode.com/problems/copy-list-with-random-pointer/submissions/1696609965/

APPROACH-1) USING MAP
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        map<Node*, Node*> mp;
        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;
        while(curr) {
            Node* temp = new Node(curr->val);
            mp[curr] = temp;
            if(newHead == NULL) {
                newHead = temp;
                prev = newHead;
            } else {
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }
        // RANDOM POINTER
        curr = head;
        Node* newCurr = newHead;
        while(curr) {
            if(curr->random == NULL) {
                newCurr->random = NULL;
            } else {
                newCurr->random = mp[curr->random];
            }
            
            newCurr = newCurr->next;
            curr = curr->next;
        }
        return newHead;
    }
};


APPROACH-2)0(1)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        Node* curr = head;
        
        while(curr) {
            Node* currNext = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = currNext;
            curr = currNext;
        }
        
        //Deep copy of random pointers
        curr = head;
        while(curr && curr->next) {
            if(curr->random == NULL) {
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        //Deep copy of next pointers and recovering old linked list
        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr          = head;
        while(curr && newCurr) {
            curr->next    = curr->next ? curr->next->next : NULL;
            
            newCurr->next = newCurr->next ? newCurr->next->next : NULL;
            
            curr = curr->next;
            newCurr = newCurr->next;
        }
       
        return newHead;        
    }
};
