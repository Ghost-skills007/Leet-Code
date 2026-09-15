#include <vector>
#include <algorithm>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr)
            return nullptr;

        ListNode* temp = head;
        std::vector<int> x;

        while (temp) {
            x.push_back(temp->val);
            temp = temp->next;
        }

        std::reverse(x.begin(), x.end());

        ListNode* newHead = new ListNode(x[0]);
        temp = newHead;

        for (int i = 1; i < x.size(); ++i) {
            ListNode* mover = new ListNode(x[i]);
            temp->next = mover;
            temp = temp->next;
        }

        return newHead;
    }
};