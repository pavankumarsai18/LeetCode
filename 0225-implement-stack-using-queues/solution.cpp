class MyStack {
private:
    vector<int> queue;
public:
    MyStack() 
    {   
    }
    
    void push(int x) 
    {
        queue.push_back(x);
    }
    
    int pop() 
    {
        if(empty() == true) return -1;
        int result =  queue[queue.size()-1];
        queue.pop_back();
        return result;
    }
    
    int top() 
    {
        return queue[queue.size()-1];
        
    }
    
    bool empty() 
    {
        return queue.size() == 0;   
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
