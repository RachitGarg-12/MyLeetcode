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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a="",b="";
        while(l1!=NULL){
            a+=l1->val+'0';
            l1=l1->next;
        }
        while(l2!=NULL){
            b+=l2->val+'0';
            l2=l2->next;
        }
        string s="";
        int i=a.size()-1,j=b.size()-1,carry=0;
        while(i>=0 || j>=0){
            int cur=(i>=0?(a[i]-'0'):0)+(j>=0?(b[j]-'0'):0)+carry;
            s+=(cur%10)+'0';
            carry=cur/10;
            i--;j--;
        }
        if(carry){s+=carry+'0';}
        reverse(s.begin(),s.end());
        int k=1,n=s.size();
        ListNode* root=new ListNode(s[0]-'0');
        ListNode* temp=root;
        while(k<n){
            temp->next=new ListNode(s[k]-'0');
            temp=temp->next;
            k++;
        }
        return root;
    }
};