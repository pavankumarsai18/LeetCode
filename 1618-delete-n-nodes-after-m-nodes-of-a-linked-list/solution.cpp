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
    ListNode* deleteNodes(ListNode* head, int m, int n) 
    {
        int count = 0;
        
        ListNode* listNodes;
        ListNode* lastMNode;
        
        listNodes = head;
        lastMNode = head;
        
        while(listNodes != nullptr)
        {
            int mCount, nCount;
            mCount = m; nCount = n;
            while(listNodes && mCount)
            {
                lastMNode = listNodes;
                listNodes = listNodes->next;
                mCount--;
            }
            
            while(nCount && listNodes)
            {
                listNodes = listNodes->next;
                nCount--;
            }

            lastMNode->next = listNodes;
        }
        return head;
        
    }
};
