class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode less(0), greater(0);
        ListNode* l = &less;
        ListNode* g = &greater;

        while (head != NULL) {
            if (head->val < x) {
                l->next = head;
                l = l->next;
            } else {
                g->next = head;
                g = g->next;
            }

            head = head->next;
        }

        g->next = NULL;
        l->next = greater.next;

        return less.next;
    }
};