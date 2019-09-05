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
    ListNode* reverseList(ListNode* head) {
        if(head == 0)
            return head;
        
        ListNode* cur_node = head;
        ListNode* result;
        vector<ListNode*>p;
        
        while(cur_node != 0)
        {
            p.push_back(cur_node);
            if(cur_node->next == 0)
            {
                result = cur_node;
            }
            cur_node = cur_node->next;
            
        }
        
        for(int i = p.size() - 1; i >= 1; i--)
        {
            p[i]->next = p[i-1];
        }
        p[0]->next = 0;
        
        return result;
        
    }
};
