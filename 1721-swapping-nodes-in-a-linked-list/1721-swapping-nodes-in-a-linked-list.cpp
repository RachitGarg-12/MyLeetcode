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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode *temp=head;
        ListNode *front,*back;
        while(temp!=NULL){
            n++;
            if(n==k){front=temp;}
            temp=temp->next;
        }
        temp=head;
        int i=0;
        while(i<(n-k)){
            i++;
            temp=temp->next;
        }
        back=temp;
        int t=front->val;
        front->val=back->val;
        back->val=t;
        return head;
    }
};