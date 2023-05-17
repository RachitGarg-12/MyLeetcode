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
        ListNode *temp=head;
        vector<int> a;
        while(temp!=NULL){
            a.push_back(temp->val);
            temp=temp->next;
        }
        int l=a.size();
        int ans=0;
        for(int i=0;i<l/2;i++){
            ans=max(ans,a[i]+a[l-i-1]);
        }
        return ans;
    }
};