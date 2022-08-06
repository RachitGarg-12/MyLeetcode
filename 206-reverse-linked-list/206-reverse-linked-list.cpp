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
    ListNode* reverseList(ListNode* head) {
        vector<int> a;
        ListNode* temp=head;
        while(temp!=NULL){
            a.push_back(temp->val);temp=temp->next;
        }
        int n=a.size();
        temp=head;int i=n-1;
        while(temp!=NULL){ temp->val=a[i];i--;temp=temp->next;}
        return head;
    }
};