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
    ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *cur = dummy, *nex = dummy, *pre = dummy;
    int count = 0;

    while (cur->next != nullptr) {
        cur = cur->next;
        count++;
    }

    while (count >= k) {
        cur = pre->next;
        // 2 -> 1(pre) -> 3 (cur) -> 4(nex) -> 5
        nex = cur->next;
        for (int i = 1; i < k; i++) {
            cur->next = nex->next;
            // pre -> 1 (cur) -> 3 -> 4 -> 5
            // pre -> 2 -> 1(cur) -> 4 -> 5
            nex->next = pre->next;
            // 2 (nex) -> 1 (cur) -> 3 -> 4 -> 5
            // 3 (nex) -> 2 -> 1 (cur) -> 4 -> 5
            pre->next = nex;
            // pre -> 2 (nex) -> 1 (cur) -> 3 -> 4 -> 5
            // pre -> 3 (nex) -> 2 -> 1 (cur) -> 4 -> 5
            nex = cur->next;
            // pre -> 2 -> 1(cur) -> 3(nex) -> 4 -> 5
            // pre -> 3 -> 2 -> 1 (cur) -> 4(nex) -> 5
        }
        pre = cur;
        // 3 -> 2 -> 1 (pre, cur) -> 4(nex) -> 5
        count -= k;
    }

    return dummy->next;
    }
};