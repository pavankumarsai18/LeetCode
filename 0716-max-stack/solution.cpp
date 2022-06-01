class LinkedList
{
public:
    int val;
    LinkedList* next;
    LinkedList* prev;
    
    LinkedList(int val)
    {
        this->val  = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


class MaxStack 
{
private:
    map<int, vector<LinkedList*>> maxStack;
    LinkedList* head;
    LinkedList* tail;
    
public:
    MaxStack() 
    {
        head = new LinkedList(-1);
        tail = new LinkedList(-1);
        
        head->next = tail;
        tail->prev = head;
    }
    
    void addToHead(LinkedList* node)
    {
        node->next         = head->next;
        node->prev         = head;
        (head->next)->prev = node;
        head->next         = node;
    }
    void printList()
    {
        LinkedList* node = head;
        while(node != tail)
        {
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl;
    }
    void remove(LinkedList* node)
    {
        LinkedList* prevNode = node->prev;
        LinkedList* nextNode = node->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        
        node->next = nullptr;
        node->prev = nullptr;
        delete node;
        node = nullptr;
    }
    
    
    void push(int x) 
    {
        // cout<<"push "<<x<<endl;
        LinkedList* node = new LinkedList(x);
        
        if(maxStack.find(x) == maxStack.end())
        {
            maxStack[x] = vector<LinkedList*>();
        }
        maxStack[x].push_back(node);
        addToHead(node);
        // printList();
    }
    
    
    int pop() 
    {
        // cout<<"pop ";

        LinkedList* node = head->next;
        int val = node->val;
        
        remove(node);
        
        maxStack[val].pop_back();
        
        if(maxStack[val].size() == 0)
        {
            maxStack.erase(val);
        }
        // cout<<val<<endl;
        // printList();

        return val;
    }
    
    int top() 
    {
        // cout<<"top ";

        LinkedList* node = head->next;
        // cout<<node->val<<endl;
        
        // printList();

        return node->val;
    }
    
    int peekMax() 
    {
        // cout<<"peekMax ";
        
        auto maxItr = maxStack.end();
        maxItr--;
        
        // cout<< (*maxItr).first<<endl;;
        // printList();

        return (*maxItr).first;
    }
    
    int popMax() 
    {
        // cout<<"popMax ";
        int key = peekMax();
        
        LinkedList* node = (maxStack[key])[maxStack[key].size()-1];
        remove(node);
        
        maxStack[key].pop_back();
        
        if(maxStack[key].size()==0)
            maxStack.erase(key);
        
        // cout<<key<<endl;
        // printList();

        return key;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
