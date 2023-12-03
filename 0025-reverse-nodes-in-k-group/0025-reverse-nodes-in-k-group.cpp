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
    ListNode* rev(ListNode *head){
        ListNode* prev=NULL, *cur=head;
        while(cur!=NULL){
            ListNode *nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    ListNode* getkthNode(ListNode* cur,int k){
        k--;
        while(k-- && cur!=NULL){
            cur=cur->next;
        }
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp!=NULL){
            ListNode* kth=getkthNode(temp,k);
            if(kth==NULL){
                if(prevNode){
                    prevNode->next=temp;
                }
                break;
            }
            ListNode* nex=kth->next;
            kth->next=NULL;
            rev(temp);
            if(temp==head){
                head=kth;
            }
            else{
                prevNode->next=kth;
            }
            prevNode=temp;
            temp=nex;
        }
        return head;
    }
};