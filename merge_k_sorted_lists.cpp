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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::map<int, ListNode*> dict{};
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for (auto list: lists)
        {
            ListNode* toDoNode = list;
            while (toDoNode != nullptr)
            {
                ListNode* nextNode = toDoNode->next;

                if(dict[toDoNode->val])
                {
                    toDoNode->next = dict[toDoNode->val];
                    dict[toDoNode->val] = toDoNode;
                }
                else
                {
                    dict[toDoNode->val] = toDoNode;
                    toDoNode->next = nullptr;
                }
                toDoNode = nextNode;
            }
        }

        for (auto [index, list]: dict)
        {
            if (head == nullptr)
            {
                head = list;
                tail = list;
                while (tail->next != nullptr)
                    tail = tail->next;
            }
            else
            {
                tail->next = list;
                while (tail->next != nullptr)
                    tail = tail->next;
            }
        }
        return head;
    }
};