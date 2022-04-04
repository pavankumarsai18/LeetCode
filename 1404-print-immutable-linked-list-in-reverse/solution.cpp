/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) 
    {
        vector<ImmutableListNode*> values;
        ImmutableListNode* curNode = head;
        while(curNode)
        {
            values.push_back(curNode);
            curNode = curNode->getNext();
        }
        
        for(int i = values.size() -1;i >= 0; i--)
        {
            values[i]->printValue();
        }
        
        
        
    }
};
