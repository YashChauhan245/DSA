https://leetcode.com/problems/reverse-nodes-in-k-group/description/

class Solution {
public:
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {
            ListNode* kThNode = getKthNode(temp, k);
            if (kThNode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }

            ListNode* nextGroup = kThNode->next;
            kThNode->next = NULL;

            ListNode* reversedHead = reverseLinkedList(temp);

            if (temp == head) {
                head = reversedHead;
            } else {
                prevLast->next = reversedHead;
            }

            prevLast = temp;
            temp = nextGroup;
        }

        return head;
    }
};


