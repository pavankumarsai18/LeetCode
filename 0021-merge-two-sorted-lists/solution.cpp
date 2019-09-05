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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == 0)
        {
            return l2;
        }
        else if(l2 == 0)
        {
            return l1;
        }
        
        ListNode *a = l1;
        ListNode *b = l2;
        
        
        //make a to have the smallest element
        if(a->val > b->val)
        {
            ListNode* temp = a;
            a = b;
            b = temp;
        }
        
        ListNode *result = a;
        
        //run the loop till one of the pointerreaches the tail of the list
        
        while(a != 0 && b!= 0)
        {
            if(a->next != 0)
            {
                if(a->val <= b->val && b->val <= a->next->val)
                {

                    if(b->next != 0)
                    {
                        ListNode*temp = b->next;
                        b->next = a->next;
                        a->next = b;
                        a = a->next;
                        b = temp; 
                    }

                    else
                    {
                        b->next = a->next;
                        a->next = b;
                        break;
                    }

                }

                else
                {
                    a = a->next;
                }
            }
            
            else
            {
                if(a->val <= b->val)
                {
                    a->next = b;
                    break;
                }
                else
                {
                    break;
                }
                
            }

            
        }
        return result;
    }
};
