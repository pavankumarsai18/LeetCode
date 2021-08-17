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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* result = head;
        
        ListNode* firstNode;
        ListNode* secondNode;
        
        firstNode = head;
        secondNode = head==nullptr? nullptr:head->next;
        
        while(firstNode != nullptr && secondNode != nullptr)
        {
            int temp = firstNode->val;
            if(secondNode != nullptr)
            {
                firstNode->val = secondNode->val;
            }
            else
            {
                break;
            }
            secondNode->val = temp;
            
            if(secondNode->next != nullptr){
                firstNode = secondNode->next;
            }
            else
            {
                break;
            }
            if(secondNode->next != nullptr && secondNode->next->next != nullptr)
            {
                secondNode = (secondNode->next)->next;
            }
            else
            {
                break;
            }
        }
        
        return result;
    }
};
