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
    void deleteNode(ListNode* node) {
        
        while(true)
        {
            node->val = node->next->val;
            
            if(node->next->next == 0)
            {
                node->next = 0;
                break;
            }
            node = node->next;
            
        }
    
    }
};
