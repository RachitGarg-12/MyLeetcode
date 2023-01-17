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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode *temp=head;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int r1=0,r2=m-1,c1=0,c2=n-1;
        int dir=1;
        while(c1<=c2 && r1<=r2){
            if(dir==1){
            for(int i=c1;i<=c2;i++){ if(temp==NULL){break;}
                ans[r1][i]=temp->val;temp=temp->next;}
                r1++;dir=2;
            }
            else if(dir==2){
            for(int i=r1;i<=r2;i++){if(temp==NULL){break;}
                ans[i][c2]=temp->val;temp=temp->next;}
                c2--;dir=3;
            }
            else if(dir==3){
            for(int i=c2;i>=c1;i--){if(temp==NULL){break;}
                ans[r2][i]=temp->val;temp=temp->next;}
                r2--;dir=4;
            }
            else if(dir=4){
            for(int i=r2;i>=r1;i--){if(temp==NULL){break;}
                ans[i][c1]=temp->val;temp=temp->next;}
                c1++;dir=1;
            }
            if(temp==NULL){break;}
        }
        return ans;
    }
};