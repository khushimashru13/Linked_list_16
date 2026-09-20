class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;

            // Find the correct position
            ListNode* prev = dummy;

            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr
            curr->next = prev->next;
            prev->next = curr;

            curr = next;
        }

        return dummy->next;
    }
};