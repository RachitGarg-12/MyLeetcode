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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){return head;}
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
            swap(temp->val,temp->next->val);
            if(temp->next->next!=NULL)temp=temp->next->next;
            else{break;}}
            else{break;}
        }
        return head;
    }
};