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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){return head;}
        vector<int> l,m;
        ListNode *temp=head;
        while(temp!=NULL){
            if(temp->val<x){l.push_back(temp->val);}
            else{m.push_back(temp->val);}
            temp=temp->next;
        }
        int i=0,j=0;
        if(l.size()>0){head->val=l[0];i++;}
        else{head->val=m[0];j++;}
        temp=head;
        temp=temp->next;
        while(i<l.size()){
            temp->val=l[i];
            i++;
            temp=temp->next;
        }
        while(j<m.size()){
            temp->val=m[j];
            j++;
            temp=temp->next;
        }
        return head;
    }
};