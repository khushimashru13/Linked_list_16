class Solution {
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int result = 0;
        int count = 0;

        ListNode* curr = head;

        while (curr != nullptr) {
            count++;

            // Choose current node with probability 1/count
            if (rand() % count == 0) {
                result = curr->val;
            }

            curr = curr->next;
        }

        return result;
    }
};