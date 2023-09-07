class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = nullptr;
        ListNode* rev = reverseList(head->next);
        head->next->next = head;
        head->next = prev;
        return rev;
    }
};