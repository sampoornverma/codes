/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int count=0;
        ListNode *h=head;
        while(h!=nullptr){
            count++;
            h=h->next;
        }
        h=head;
        vector<int> ans;

        while(h!=nullptr){
            ans.push_back(h->val);
            h=h->next;
        }
        int n=count;
        int maxi=0;
        for(int i=0;i<n/2;i++){
            maxi=max(maxi,ans[i]+ans[n-1-i]);
        }
        return maxi;
    }
};