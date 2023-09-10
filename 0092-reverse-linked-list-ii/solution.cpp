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
    vector<ListNode*> reverse(ListNode* head) {
        // Returns head and tail of reversed Linked List
        ListNode* revHead = nullptr;
        ListNode* revTail = head;
        ListNode* cur = head;

        ListNode* prev = nullptr;
        while (cur) {
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        revHead = prev;
        return {revHead, revTail};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == right) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = head;
        ListNode* prev = dummy;
        ListNode* leftPrev = nullptr;
        ListNode* rightNext = nullptr;
        ListNode* headRemoved = nullptr;
        int curIdx = 1;

        while (curIdx != right) {
            if (curIdx == left) {
                leftPrev = prev;
                headRemoved = cur;
                prev->next = nullptr;
            }
            prev = cur;
            cur = cur->next;
            curIdx++;
        }

        rightNext = cur->next;
        cur->next = nullptr;

        auto nodes = reverse(headRemoved);
        leftPrev->next = nodes[0];
        nodes[1]->next = rightNext;

        return dummy->next;

    }
};
