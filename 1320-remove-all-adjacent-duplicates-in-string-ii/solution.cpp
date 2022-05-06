class Solution {    
public:
    template<class T>
    void printStack(stack<T> & s)
    {
        stack<T> copy = s;
        while(copy.size())
        {
            cout<<copy.top()<<" ";
            copy.pop();

        }
        cout<<endl;
    }
    
    string removeDuplicates(string s, int k) 
    {
        
        stack<char> elements;
        stack<int> count;
        
        elements.push(s[0]);
        count.push(1);
        
        for(int index = 1; index < s.size(); index++)
        {
            // cout<<"index "<<index<<" "<<s[index]<<endl;
            if(elements.size() && elements.top() == s[index])
            {
                // cout<<"in if"<<endl;
                if(count.top() == k - 1)
                {
                    // cout<<"k reached\n";
                    elements.pop();
                    count.pop();
                }
                else
                {
                    // cout<<"in if else\n";
                    int T = count.top();
                    count.pop();
                    count.push(T + 1);
                }
            }
            else
            {
                // cout<<"in else\n";
                elements.push(s[index]);
                count.push(1);
            }
            
            // printStack(elements);
            // printStack(count);
        }
        
       string result = "";
        
       while(elements.size())
       {
           char item = elements.top();
           for(int i = 0; i < count.top(); i++)
           {
               result += item;
           }
           count.pop();
           elements.pop();
       }
        
        
       for(int i = 0; i < result.size()/2; i++)
       {
           swap(result[i], result[result.size() - 1 - i]);
       }
        
       return result;
    }
};
