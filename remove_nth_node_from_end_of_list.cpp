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
        ListNode* end = head;
        ListNode* target = head;
        ListNode* beforeTarget = head;
        while (n > 0)
        {
            end = end->next;
            n--;
        }

        while (end != nullptr)
        {
            end = end->next;
            beforeTarget = target;
            target = target->next;
        }

        if (target == head)
        {
            head = head->next;
            delete target;
        }
        else
        {
            beforeTarget->next = target->next;
            delete target;
        }
        return head;
    }
};