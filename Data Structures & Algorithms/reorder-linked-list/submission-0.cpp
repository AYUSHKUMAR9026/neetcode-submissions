class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }

        ListNode* temp = head;
        int count = 0;

        while (temp) {
            count++;
            temp = temp->next;
        }

        int x = count / 2;
        temp = head;

        while (x--) {
            temp = temp->next;
        }

        ListNode* prev = NULL;

        while (temp) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second->next) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }
};