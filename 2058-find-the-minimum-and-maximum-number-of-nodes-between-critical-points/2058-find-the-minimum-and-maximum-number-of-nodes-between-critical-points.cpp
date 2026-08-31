class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> a;

        int i = 1;
        ListNode* x = head->next;
        ListNode* prev = head;

        while (x != nullptr && x->next != nullptr) {

            if (prev->val < x->val && x->val > x->next->val) {
                a.push_back(i);
            }

            else if (prev->val > x->val && x->val < x->next->val) {
                a.push_back(i);
            }

            prev = x;
            x = x->next;
            i++;
        }

        if (a.size() < 2)
            return {-1, -1};

        int maxi = a.back() - a.front();

        int mini = INT_MAX;

        for (int j = 1; j < a.size(); j++) {
            mini = min(mini, a[j] - a[j - 1]);
        }

        return {mini, maxi};
    }
};