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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* temp=head;
        while(temp && temp->next){
            int cur=__gcd(temp->val,temp->next->val);
            ListNode* node=new ListNode(cur);
            node->next=temp->next;
            temp->next=node;
            temp=node->next;
        }
        return head;
    }
};