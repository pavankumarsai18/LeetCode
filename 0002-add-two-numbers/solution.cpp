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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* curr_1 = l1;
        ListNode*curr_2 = l2;
        
        
        int len_1 = 0;
        int len_2 = 0;
        while(curr_1 != nullptr)
        {
            len_1 ++;
            curr_1 = curr_1->next;
        }
        while(curr_2 != nullptr)
        {
            len_2 ++;
            curr_2 = curr_2->next;
        }
        
        if(len_1 > len_2)
        {
            swap(l1, l2);
        }
        
        // cout<<len_1<<" "<<len_2<<endl;
        
        curr_1 = l1;
        curr_2 = l2;
        // cout<<curr_1->val<<" "<<curr_2->val<<endl;
        
        int carry = 0;
        
        auto tail = curr_2;
        while(curr_1 != nullptr || curr_2 != nullptr )
        {
            int temp = 0;
            // cout<<temp<</endl;
            
            if(curr_1 == nullptr && curr_2 != nullptr)
                temp =  curr_2->val + carry;
            else if(curr_1 != nullptr && curr_2 == nullptr)
                temp =  curr_1->val + carry;
            else if(curr_1 != nullptr && curr_2 != nullptr)
                temp = curr_1->val + curr_2->val + carry;

            if(temp >= 10)
            {
                temp -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            curr_2->val = temp;
            if(curr_2 != nullptr)
            {
                tail = curr_2;
                curr_2 = curr_2->next;
            }
            if(curr_1 != nullptr)
                curr_1 = curr_1->next;
            
        }
        if(carry == 1)
        {
            tail->next = new ListNode(1);
        }
        
        return l2;
    }
};
