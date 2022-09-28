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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;ListNode *temp=head;
        while(temp!=NULL){
            temp=temp->next;l++;
        }
        int st=l-n+1;
        if(st==1){
            head=head->next;
            return head;
        }
        temp=head;
        for(int i=1;i<st;i++){
            if(i==st-1){temp->next=temp->next->next;break;}
            temp=temp->next;
        }
        return head;
    }
};