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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        int jump=b-a+1;
        while(a>1){
            temp=temp->next;
            a--;
        }
        ListNode *rem=temp->next;
        while(jump--){
            rem=rem->next;
        }
        temp->next=list2;
        while(temp){
            if(temp->next){
                temp=temp->next;
            }
            else{break;}
        }
        temp->next=rem;
        return list1;
    }
};