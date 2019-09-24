/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr)
            return head;
        
        ListNode* curr = head;
        while(curr != nullptr)
        {
            if(curr->next != nullptr)
            {
                if(curr->val == curr->next->val)
                {
                    auto temp = curr->next;
                    curr->next = temp->next;
                    temp->next = nullptr;
                    delete temp;
                    temp = nullptr;
                }
                else
                {
                    curr = curr->next;
                }
            }
            else
            {
                curr = curr->next;
                break;
            }
        }
        return head;
    }
};
