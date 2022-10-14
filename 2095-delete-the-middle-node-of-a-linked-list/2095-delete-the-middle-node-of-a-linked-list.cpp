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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;int n=0;
        while(temp!=NULL){
            temp=temp->next;n++;
        }
        if(n==1){return NULL;}
        n/=2;temp=head;
        if(n==1){
            ListNode *cur=temp->next;
            temp->next=temp->next->next;
            delete cur;
            return head;
        }
        for(int i=0;i<=n;i++){
            if(i==n){
                swap(temp->val,temp->next->val);
                ListNode* cur=temp->next;
                temp->next=temp->next->next;
                delete cur;
            }
            temp=temp->next;
        }
        return head;
    }
};