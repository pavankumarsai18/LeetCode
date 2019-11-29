class Solution {
public:
    string countAndSay(int n) 
    {
        vector<string> result(n, "");
        result[0] = "1";
        if(n == 1)
            return result[0];
        if(n == 2)
        {
            result[1] = "11";
            return result[1];
        }
        else if (n == 3)
        {    
            result[2] = "21";
            return result[2];
        }
        
        result[0] = "1";
        result[1] = "11";
        result[2] = "21";
        for(int i = 3; i < n; i++)
        {
            string temp = "";
            string prev = result[i - 1];
            
            for(int j = 0; j < prev.size(); j++)
            {
                stack<char> r;
                r.push(prev[j]);
                do
                {
                    if(j < prev.size() - 1 && r.top() == prev[j+1])
                    {   r.push(prev[j + 1]);
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }while(j < prev.size() - 1);
                
                //cout<<r.size()<<endl;
                temp += static_cast<char>(r.size() + 48);
                temp += r.top();
                
            }
            
            result[i] = temp;
        }
        return result[n - 1];
        
    }
};
