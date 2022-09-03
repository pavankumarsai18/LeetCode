class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        queue<int> Q;
        
        for(int i = 1; i <= 9; i++)
        {
            Q.push(i);
        }
        
        int length = 1; 
        while(length < n)
        {
            queue<int> newQueue;
            
            while(!Q.empty())
            {
                int num = Q.front();
                int lastDigit = num%10;
                Q.pop();
                
                if((lastDigit + k) <= 9)
                {
                   
                    newQueue.push(num*10 + (lastDigit + k));
                }
                if(k != 0 && (lastDigit - k) >= 0)
                {
                    newQueue.push(num*10 + (lastDigit - k));
                }
            }
            
            Q = newQueue;
            length++;
        }
        
        
        vector<int> ans;
        
        while(!Q.empty())
        {
            ans.push_back(Q.front()); Q.pop();
        }
        
        return ans;
        
    }
};
