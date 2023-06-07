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
       if(k==0 || head==NULL){return head;}
       ListNode *temp=head;
       int n=1;
       while(temp->next){
            temp=temp->next;n++;
       }
       k%=n;
       if(k==0){return head;}
       temp->next=head;
       temp=head;
       int dis=n-k-1;
       while(dis--){temp=temp->next;}
       head=temp->next;
       temp->next=NULL;
       return head;
    }
};