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
    
       
  
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1) return head;
        ListNode *st=head,*en=head;int inc=k-1;
        while(inc--){
            en=en->next;
            if(en==NULL)return head;
        }
        ListNode* nexthead=reverseKGroup(en->next,k);
         ListNode *p=NULL,*c=st,*n=st->next;
        while(p!=en){c->next=p;
                    p=c;c=n;
                    if(n!=NULL) n=n->next;}
        st->next=nexthead;
        return en;
    }
};