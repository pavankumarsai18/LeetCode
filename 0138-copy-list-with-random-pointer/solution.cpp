/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(head == nullptr) 
            return nullptr;
        
        
        Node* newHead = new Node(head->val);
        
        Node* cur = head;
        Node* newCur = newHead;
    
        // Clone and interleave new Nodes
        do
        {
           
            Node* temp = cur->next;
            
            cur->next = newCur;
            newCur->next = temp;
            
            cur = newCur->next;

            newCur = (cur!=nullptr) ?new Node(cur->val): nullptr;            
            
        }while(cur);
        
        // Unweave and set the correct next and random pointers
        cur = head;
        newCur = newHead;
        do
        {
  
            if(newCur && cur->random)
                newCur->random = cur->random->next;

            Node* nextOldNode = newCur->next;
            cur = nextOldNode;
            
            Node* nextNewNode = (cur)?cur->next: nullptr;
            newCur = nextNewNode;
            
        }while(cur);
        
        cur = head;
        newCur = newHead;
        do
        {
            Node* nextOldNode = newCur->next;
            cur->next = nextOldNode;
            cur = cur->next;             // set the oldCur next ptr
            
            Node* nextNewNode = (cur)?cur->next: nullptr;
            newCur->next = nextNewNode; // set the newCur next ptr
            
            newCur = newCur->next;
            
        }while(cur);
        
        
        return newHead;
        
    }
};
