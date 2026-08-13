class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<int, vector<int>, greater<int>> q;

        for (ListNode* head : lists) {
            while (head) {
                q.push(head->val);
                head = head->next;
            }
        }

        if (q.empty())
            return NULL;

        ListNode* head = new ListNode(q.top());
        q.pop();

        ListNode* curr = head;

        while (!q.empty()) {
            curr->next = new ListNode(q.top());
            q.pop();
            curr = curr->next;}
        return head;
    }
};