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
    vector<int> nextLargerNodes(ListNode *head) {
    vector<int> v;
    while (head != nullptr)v.push_back(head->val), head = head->next;
    vector<int> ans(v.size(), 0);
    stack<pair<int, int>> s;
    for (int i = 0; i < v.size(); ++i) {
        if (s.empty())s.push({v[i], i});
        else {
            while (!s.empty() and v[i] > s.top().first) {
                ans[s.top().second] = v[i];
                s.pop();
            }
            s.push({v[i], i});
        }
    }
    return ans;
}
};