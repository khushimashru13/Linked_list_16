class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        // Find length and last node
        int n = 1;
        ListNode* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
            n++;
        }

        // Avoid unnecessary rotations
        k = k % n;
        if (k == 0)
            return head;

        // Make circular list
        temp->next = head;

        // Find new tail
        for (int i = 0; i < n - k; i++)
            temp = temp->next;

        // New head
        head = temp->next;

        // Break the circle
        temp->next = NULL;

        return head;
    }
};