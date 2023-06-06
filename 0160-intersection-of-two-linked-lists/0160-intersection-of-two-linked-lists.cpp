/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *f, ListNode *s) {
	    if(!f || !s){return NULL;}
	    ListNode* a = f;
	    ListNode* b = s;
	    while(1){
	    	if(a==b){return a;}
	    	a=a->next;
	    	b=b->next;
	    	if(!a&&!b){break;}
	    	if(!a){a = s;}
	    	if(!b){b = f;}
	    }
	    return NULL;        
    }
};