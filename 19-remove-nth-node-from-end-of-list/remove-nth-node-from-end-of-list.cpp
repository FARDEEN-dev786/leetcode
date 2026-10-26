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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode* count = head;

        while (count != nullptr) {
            k++;
            count = count->next;
        }
        if (n == k) {
            head = head->next;
            return head;
        }
        count = head;
        for (int i = 0; i < k - n-1; i++) {
            count = count->next;
        }
        count->next = count->next->next;
        return head;
    }
};