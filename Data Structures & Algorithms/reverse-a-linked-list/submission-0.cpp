class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp) {
            ListNode* nextNode = temp->next;

            temp->next = prev;

            prev = temp;
            temp = nextNode;
        }

        return prev;
    }
};