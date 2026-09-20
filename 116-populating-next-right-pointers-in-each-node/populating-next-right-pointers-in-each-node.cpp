class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        Node* leftmost = root;

        while (leftmost->left != nullptr) {
            Node* curr = leftmost;

            while (curr != nullptr) {
                // Connect left child to right child
                curr->left->next = curr->right;

                // Connect right child to next node's left child
                if (curr->next != nullptr)
                    curr->right->next = curr->next->left;

                curr = curr->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};