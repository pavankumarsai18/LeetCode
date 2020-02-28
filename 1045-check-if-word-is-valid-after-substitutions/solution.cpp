class Solution {
public:
    bool isValid(string S) 
    {
        // Realtive order of a, b, c should remain the same
        // a then b then c
        
        stack<char> order_check;
        
        for(int i = 0; i < S.length(); i++)
        {
            char c = S[i];
    
            if(c == 'a')
            {
                order_check.push(c);
            }
            else if(c == 'b')
            {
                if( !order_check.empty() && order_check.top() == 'a')
                {
                    order_check.pop();
                    order_check.push(c);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                
                if(!order_check.empty() &&order_check.top() == 'b')
                {
                    order_check.pop();
                }
                else
                {
                    return false;
                }
            }
         }
        
        if(order_check.empty())
            return true;
        return false;
        
        
        // The number of a's and b's and c's should be integer
//         unordered_map<char, int> char_count;
        
        
//         for(auto c: S)
//         {
//             auto itr = char_count.find(c);
//             if(itr == char_count.end())
//                 itr->second = 1;
//             else
//                 itr->second += 1;
//         }
           
    }
};
