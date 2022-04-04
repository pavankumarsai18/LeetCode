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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* curPtr = head;
        ListNode* firstNode = nullptr;
        ListNode* secondNode = nullptr;
        int len = 0;
        int count = 1;
        
        while(curPtr)
        {
            curPtr = curPtr->next;
            len++;
        }
        
        if(k > len/2)
        {
            k = len - k + 1;
        }
        
        curPtr = head;
        while(curPtr && count < k)
        {
            curPtr = curPtr->next;
            count++;
        }
        firstNode = curPtr;
        
        while(curPtr && count <= len - k)
        {
            curPtr = curPtr->next;
            count++;
        }
        secondNode = curPtr;
        
        // cout<<firstNode->val<<" "<<secondNode->val<<endl;
        int val = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = val;
        return head;
        
    }
};
