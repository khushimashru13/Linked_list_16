class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (head == NULL || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // Move to the node before left
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        // Reverse nodes
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;

            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};