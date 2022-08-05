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
    int getDecimalValue(ListNode* head) {
        ListNode *temp=head;
        int len=0;
        while(temp!=NULL){len++;temp=temp->next;}
         ListNode *temp2=head;int ans=0;len--;
        while(len>=0){ 
            // cout<<len<<" "<<ans<<" "<<temp2->val<<endl;
            if(temp2->val==1){ans += 1<<len;}
            temp2=temp2->next;
            len--;}
        return ans;
    }
};