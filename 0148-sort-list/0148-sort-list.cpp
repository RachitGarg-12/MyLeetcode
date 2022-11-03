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
    ListNode* sortList(ListNode* head) {
        vector<int> a;
        if(head==NULL)return head;
        ListNode *temp=head;
        while(temp!=NULL){a.push_back(temp->val);temp=temp->next;}
        temp=head;
        sort(a.begin(),a.end());
        for(auto i:a){temp->val=i;temp=temp->next;}
        return head;
    }
};