https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=daily-question&envId=2026-06-14

css Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;

        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }

        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, arr[i] + arr[n - 1 - i]);
        }

        return ans;
    }
};
