https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2026-08-31


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX;
        int maxDist = -1;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int index = 1;
        int firstCritical = -1;
        int prevCritical = -1;

        while (next != nullptr) {

            // Check if curr is a critical point
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                // First critical point
                if (firstCritical == -1) {
                    firstCritical = index;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, index - prevCritical);

                    // Distance from first critical point
                    maxDist = index - firstCritical;
                }

                prevCritical = index;
            }

            // Move the three pointers
            prev = curr;
            curr = next;
            next = next->next;

            index++;
        }

        if (maxDist == -1) {
                return {-1, -1};
        }

        return {minDist, maxDist};

    }
};
