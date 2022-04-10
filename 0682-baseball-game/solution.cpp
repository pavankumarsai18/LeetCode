class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        vector<int> operands;
        
        for(int i = 0; i < ops.size();i++)
        {
            if(ops[i] == "C")
            {
                operands.pop_back();
            }
            else if(ops[i] == "D")
            {
                operands.push_back(operands[operands.size() - 1]*2);
            }
            else if(ops[i] == "+")
            {
                
                operands.push_back(operands[operands.size()-1] + operands[operands.size()-2]);
            }
            else
            {
                operands.push_back(stoi(ops[i]));
            }
        
        }
        
        int result = 0;
        for(int i = 0; i < operands.size();i++)
        {
            result += operands[i];
        }
        return result;
    }
};
