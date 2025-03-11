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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* toMergeNode1 = list1;
        ListNode* toMergeNode2 = list2;
        ListNode* mergedNode = nullptr;
        ListNode* head = nullptr;

        if (toMergeNode1 != nullptr && toMergeNode2 != nullptr)
        {
            if (toMergeNode1->val <= toMergeNode2->val)
            {
                mergedNode = toMergeNode1;
                toMergeNode1 = toMergeNode1->next;
            }
            else
            {
                mergedNode = toMergeNode2;
                toMergeNode2 = toMergeNode2->next; 
            }
        }
        else if (toMergeNode1 != nullptr)
        {
            mergedNode = toMergeNode1;
            toMergeNode1 = toMergeNode1->next; 
        }
        else if (toMergeNode2 != nullptr)
        {
            mergedNode = toMergeNode2;
            toMergeNode2 = toMergeNode2->next; 
        }

        head = mergedNode;

        while (toMergeNode1 != nullptr && toMergeNode2 != nullptr)
        {
            if (toMergeNode1->val <= toMergeNode2->val)
            {
                mergedNode->next = toMergeNode1;
                toMergeNode1 = toMergeNode1->next;
                mergedNode = mergedNode->next;
            }
            else
            {
                mergedNode->next = toMergeNode2;
                toMergeNode2 = toMergeNode2->next;
                mergedNode = mergedNode->next;
            }
        }

        if (toMergeNode1 != nullptr)
        {
            mergedNode->next = toMergeNode1;
            toMergeNode1 = toMergeNode1->next;
            mergedNode = mergedNode->next;
        }

        if (toMergeNode2 != nullptr)
        {
            mergedNode->next = toMergeNode2;
            toMergeNode2 = toMergeNode2->next;
            mergedNode = mergedNode->next;
        }

        return head;
    }
};