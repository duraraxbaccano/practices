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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultHead;
        ListNode* resultTail;
        int sum = l1->val + l2->val;
        int carry = sum / 10;
        sum = sum % 10;
        resultTail = new ListNode(sum);
        resultHead = resultTail;
        while (l1->next != nullptr && l2->next != nullptr)
        {
            l1 = l1->next;
            l2 = l2->next;
            sum = carry + l1->val + l2->val;
            carry = sum / 10;
            sum = sum % 10;
            resultTail->next = new ListNode(sum);
            resultTail = resultTail->next;
        }
        l1 = l1->next;
        l2 = l2->next;

        while (l1 != nullptr)
        {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            resultTail->next = new ListNode(sum);
            resultTail = resultTail->next;
            l1 = l1->next;
        }
           
        while (l2 != nullptr)
        {
            sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            resultTail->next = new ListNode(sum);
            resultTail = resultTail->next;
            l2 = l2->next;
        }

        if (carry != 0)
            resultTail->next = new ListNode(carry);

        return resultHead;
    }
};