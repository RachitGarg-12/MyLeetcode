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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return {};
        }
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> g;
        for (int i = 0; i < lists.size(); ++i) {
            auto it = lists[i];
            if (it != nullptr) {
                g.push({it->val, it});
            }
        }

        ListNode* temp = nullptr;
        ListNode* ans = temp;

        while (!g.empty()) {
            pair<int, ListNode*> cur = g.top();
            g.pop();
            if (temp == nullptr) {
                temp = new ListNode(cur.first);
                ans = temp;
            }
            else {
                ListNode* x = new ListNode(cur.first);
                temp->next = x;
                temp = temp->next;
            }
            ListNode* t = cur.second;
            if (t->next != nullptr) {
                g.push({t->next->val, t->next});
            }
        }
        return ans;        
    }
};