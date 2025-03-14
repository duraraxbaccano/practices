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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = (head != nullptr && head->next != nullptr) ? head->next : head;
        ListNode* pairHead = head;
        ListNode* pairTail = nullptr;
        ListNode* newTail = nullptr;
        while(pairHead != nullptr && pairHead->next != nullptr)
        {
            pairTail = pairHead->next;
            pairHead->next = pairTail->next;
            pairTail->next = pairHead;
            if (newTail != nullptr)
                newTail->next = pairTail;
            newTail = pairHead;
            pairHead = pairHead->next;
        }
        return newHead;
    }
};