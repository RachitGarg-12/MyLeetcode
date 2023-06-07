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
        if(head->next==NULL){return head;}
        //find middle of linked list
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast && fast->next==NULL){
            slow=slow->next;
        }
        
        //reverse end of linked list
        ListNode *prev=NULL,*n=slow->next;
        while(slow){
            // ListNode *temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=n;
            if(n!=NULL){n=n->next;}
        }
        
        fast = head;
        while(prev && fast){
            if(prev->val != fast->val){
                return false;
            }
            prev = prev->next;
            fast = fast->next;
        }
        return true;
    }
};