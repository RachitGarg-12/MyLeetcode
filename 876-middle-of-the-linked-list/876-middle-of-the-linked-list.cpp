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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;temp=temp->next;
        }
        ListNode* temp2=head;len /= 2; ListNode* ans;
        while(len){
            temp2=temp2->next;
            len--;
        }
        return temp2;
    }
};