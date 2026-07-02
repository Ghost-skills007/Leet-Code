class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* curr = head;
        ListNode* net = curr->next;

        while (curr && net) {
            if (curr->val == net->val) {
                curr->next = net->next;
                net = curr->next;
            } else {
                curr = curr->next;
                net = curr->next;
            }
        }

        return head;
    }
};