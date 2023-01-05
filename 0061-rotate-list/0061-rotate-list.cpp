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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){return head;}
        ListNode *temp=head;
        vector<int> a;
        while(temp!=NULL){
            a.push_back(temp->val);
            temp=temp->next;
        }
        int n=a.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[(i+k)%n]=a[i];
        }
        temp=head;
        temp=temp->next;
        head->val=ans[0];
        for(int i=1;i<n;i++){
            temp->val=ans[i];
            temp=temp->next;
        }
        return head;
    }
};