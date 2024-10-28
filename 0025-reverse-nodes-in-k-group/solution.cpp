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
    void printList(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }

        cout << endl;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;

        while (cur) {
            ListNode* next_node = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next_node;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int size = 0;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* prev_sublist_tail = dummy;
        ListNode* cur_sublist_head = head;

        while (cur) {
            cur_sublist_head = cur;
            int num_nodes = 0;
            ListNode*prev = nullptr;
            while (cur && num_nodes != k) {
                num_nodes++;
                prev = cur;
                cur = cur->next;
            }

            if (num_nodes < k) {
                prev_sublist_tail = cur;
            } else {
                prev_sublist_tail->next = nullptr;

                ListNode* next_node = cur;
                prev->next = nullptr;
                ListNode* reversed_sublist_head = reverse(cur_sublist_head);

                prev_sublist_tail->next = reversed_sublist_head;

                cur_sublist_head->next = next_node;
                prev_sublist_tail = cur_sublist_head;
                
            }
        }


        return dummy->next;
        
    }
};

