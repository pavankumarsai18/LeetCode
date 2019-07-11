// *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };

class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        int length = 1;
        ListNode* cur_node = head;
        
        while(cur_node->next != NULL)
        {
            cur_node = cur_node->next;
            length++;
        }
        
        //cout<<length<<endl;
        
        int result_index;
        
        if(length%2 == 0){
            result_index = (length/2) + 1;
            //cout<<result_index<<endl;
            cur_node = head;

            while(result_index > 1)
            {
                cur_node = cur_node->next;
                result_index --;
            }
        }
        else
        {
            result_index = length/2;
            //cout<<result_index<<endl;
            cur_node = head;
        
            while(result_index > 0)
            {
                cur_node = cur_node->next;
                result_index --;
            }
        }
        
        
        
        //cout<<cur_node->val;
        //ListNode result = &cur_node;
        
        return cur_node;
    }
};
