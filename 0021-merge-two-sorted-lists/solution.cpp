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
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        ListNode* cur = dummy;
        while (cur1 != nullptr && cur2 != nullptr) {
            ListNode* nextNode;
            if (cur1->val < cur2->val) {
                nextNode = cur1->next;
                cur->next = cur1;
                cur = cur->next;
                cur->next = nullptr;

                cur1 = nextNode;
            } else {
                nextNode = cur2->next;
                cur->next = cur2;
                cur = cur->next;
                cur->next = nullptr;

                cur2 = nextNode;
            }
        }

        if (cur1) {
            cur->next = cur1;
        } else {
            cur->next = cur2;
        }

        return ans->next;
    }
};
