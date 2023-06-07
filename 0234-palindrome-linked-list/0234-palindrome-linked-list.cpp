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
    //O(N)time and O(1)space
    bool isPalindrome(ListNode* head) {
        ListNode *temp=head;
        ListNode *rev=NULL;
        while(temp){
            ListNode *t=new ListNode(temp->val);
            t->next=rev;
            rev=t;
            temp=temp->next;
        }
        while(rev && head){
            // cout<<rev->val<<" "<<head->val<<endl;
            if(rev->val!=head->val){return false;}
            rev=rev->next;
            head=head->next;
        }
        return true;
    }
};