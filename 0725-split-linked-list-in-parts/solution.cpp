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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;

        ListNode* cur = head;

        while (cur) {
            ++size;
            cur = cur->next;
        }


        int numInEach = size/k;
        int remainder = size%k;
        int partIdx = 0;
        vector<ListNode*> result(k, nullptr);
        cur = head;

        while (cur) {
            int numNodes = numInEach;
            if (remainder) {
                numNodes++;
                remainder--;
            }

            ListNode* partHead = cur;
            while(cur && numNodes) {
                numNodes--;
                if (numNodes == 0) {
                    break;
                }

                cur = cur->next;
            }

            result[partIdx++] = partHead;
            ListNode* nextNode = cur->next;
            cur->next = nullptr;

            cur = nextNode;
        }

        return result;
    }
};
