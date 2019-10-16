class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> Points;
        
        for(int i = 0; i < ops.size(); i++)
        {
            
            if(ops[i] == "C")
            {
                Points.pop();   
            }
            else if(ops[i] == "+")
            {
                int x = Points.top();
                Points.pop();
                int y = Points.top();
                Points.push(x);
                Points.push(x+y);
            }
            else if(ops[i] == "D")
            {
                Points.push(2*Points.top());
                
            }
            
            else
            {   
                Points.push(string_to_int(ops[i]));
            }
            //std::cout<<Points.top()<<std::endl;
        }
        int sum = 0;
        while(!Points.empty())
        {
            sum += Points.top();
            Points.pop();
        }
        
        return sum;
    }
    
    int string_to_int(const string& s)
    {
        int result = 0;
        if(s[0] == '-')
        {
            for(int i = 1; i < s.size(); i++)
            {
                result += int(s[i]) - 48;
                if(i < s.size() - 1)
                    result *= 10;
            }
            return -1*result;
        }
        else
        {
            for(int i = 0; i < s.size(); i++)
            {
                result += int(s[i]) - 48;
                if(i < s.size() - 1)
                    result *= 10;
            }
            return result;
        }
    }
};
