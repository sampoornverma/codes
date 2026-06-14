class Solution {
public:
    int pairSum(ListNode* head) {

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        int ans = 0;

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};