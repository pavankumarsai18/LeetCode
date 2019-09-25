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
    ListNode* removeElements(ListNode* head, int val) {
        auto curr = head;
        ListNode* prev = nullptr;
        while(curr != nullptr)
        {
            if(curr->val == val)
            {
                if(prev == nullptr)
                {
                    curr = curr->next;
                    delete head;
                    head = curr;
                }
                else
                {
                    auto temp = curr->next;
                    prev->next = curr->next;
                    delete curr;
                    curr = temp;
                }
                
            }
            else
            {
                if(prev == nullptr)
                {
                    prev = head;
                    curr = curr->next;
                }
                else
                {
                    prev = prev->next;
                    curr = curr->next;
                }
                
            }
        }
        return head;
        
    }
    
};
