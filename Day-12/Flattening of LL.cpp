class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp->child = l1;
                l1 = l1->child;
            }
            else {
                temp->child = l2;
                l2 = l2->child;
            }

            temp = temp->child;
            temp->next = NULL;
        }

        if (l1)
            temp->child = l1;
        else
            temp->child = l2;

        return dummy.child;
    }

    ListNode* flattenLinkedList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* right = flattenLinkedList(head->next);

        return merge(head, right);
    }
};
