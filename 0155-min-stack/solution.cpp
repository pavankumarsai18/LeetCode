class MinStack {
private:
    vector<int> S;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        S = vector<int>();
    }
    
    void push(int x) {
        
        if(S.size() > 0 && x < min)
        {
            min = x;
        }
        else if(S.size() == 0)
        {
            min = x;
        }
        S.push_back(x);

        
    }
    
    void pop() {
        int lastElement = S[S.size() - 1];
        S.pop_back();
        if(S.size() > 0 && lastElement  == min)
        {
            min = S[0];
            for(auto itr = S.begin(); itr != S.end(); itr++)
            {
                if(*itr < min)
                    min = *itr;
            }
        }
        
    }
    
    int top() {
        return S[S.size() - 1];
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
