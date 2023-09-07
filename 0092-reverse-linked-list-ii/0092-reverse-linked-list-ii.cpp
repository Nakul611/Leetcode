/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;
        if (m > 1) {
            head->next = reverseBetween(head->next, m-1, n-1);
            return head;
        }
        if (n > 1) {
            ListNode *ret = reverseBetween(head->next, m, n - 1);
            ListNode *tmp = head->next->next;
            head->next->next = head;
            head->next = tmp;
            return ret;
        }
        return head;
    }
};