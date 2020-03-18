class Solution {
public:
    string solveEquation(string equation) 
    {
        
        string LHS = "";
        string RHS = "";
        
        bool equal_encountered = false;
        for(char c: equation)
        {
            if(c == '=' && equal_encountered == false)
            {
                equal_encountered = true;
                continue;
            }
            
            if(equal_encountered)
            {
                RHS += c;
            }
            else
            {
                LHS += c;
            }
        }
        
        // cout<<"LHS "<<LHS<<endl;
        // cout<<"RHS "<<RHS<<endl;
        
        vector<string> l_operands;
        vector<string> l_operators;
        
        for(int i = 0; i < LHS.size(); i++)
        {
            string op = "";
            if(i == 0 && LHS[0] != '+' && LHS[0] != '-')
            {
                op = "+";
                l_operators.push_back(op);
                string operand = "";
                
                while(i < LHS.size() && LHS[i] != '+' && LHS[i] != '-')
                {
                    operand += LHS[i];
                    if(i + 1 < LHS.size() && (LHS[i+1] == '+' || LHS[i+1] == '-') )
                        break;
                    else
                        i++;
                }
                
                l_operands.push_back(operand);
            }
            else if(LHS[i] == '+' || LHS[i] == '-')
            {
                op += LHS[i];
                l_operators.push_back(op);
            }
            else
            {
                string operand = "";
                
                while(i < LHS.size() && LHS[i] != '+' && LHS[i] != '-')
                {
                    operand += LHS[i];
                    if(i + 1 < LHS.size() && (LHS[i+1] == '+' || LHS[i+1] == '-') )
                        break;
                    else
                        i++;
                }
                
                l_operands.push_back(operand);
            }
        }
        
//         for(string s: l_operands)
//             cout<<s<<" ";
//         cout<<endl;
        
//         for(string s: l_operators)
//             cout<<s<<" ";
//         cout<<endl;
        
        vector<string> r_operands;
        vector<string> r_operators;
        for(int i = 0; i < RHS.size(); i++)
        {
            string op = "";
            if(i == 0 && RHS[i] != '+' && RHS[i] != '-')
            {
                op = "+";
                r_operators.push_back(op);
                string operand = "";
                while(i < RHS.size() && RHS[i] != '+' && RHS[i] != '-')
                {
                    operand += RHS[i];
                    if(i + 1 < RHS.size() &&  (RHS[i + 1] == '+' || RHS[i + 1] == '-' ))
                        break;
                    else
                        i++;
                }
                r_operands.push_back(operand);
            
            }
            else if(RHS[i] == '+' || RHS[i] == '-')
            {
                op += RHS[i];
                r_operators.push_back(op);
            }
            else
            {
                string operand = "";
                while(i < RHS.size() && RHS[i] != '+' && RHS[i] != '-')
                {
                    operand += RHS[i];
                    if(i + 1 < RHS.size() &&  (RHS[i + 1] == '+' || RHS[i + 1] == '-' ))
                        break;
                    else
                        i++;
                }
                r_operands.push_back(operand);
            
            }
        }
        
//         for(string s: r_operands)
//             cout<<s<<" ";
//         cout<<endl;
        
//         for(string s: r_operators)
//             cout<<s<<" ";
//         cout<<endl;
        
        
        int l_x_count = 0;
        unordered_set<int> l_x_ind;
        for(int i = 0; i < l_operands.size(); i++)
        {
            if( (l_operands[i])[l_operands[i].size() - 1] == 'x' )
            {
                l_x_ind.insert(i);
                
                int c = 1;
                
                if(l_operands[i].size() - 1 > 0)
                {
                    c = stoi(l_operands[i].substr(0, (l_operands[i]).size() - 1));
                }

                if(l_operators[i] == "-")
                {c *= -1;}

                
                l_x_count += c;
            }
        }
        // cout<<"l_x_count "<<l_x_count<<endl;

        int r_x_count = 0;
        unordered_set<int> r_x_ind;
        for(int i = 0; i < r_operands.size(); i++)
        {
            if( (r_operands[i])[r_operands[i].size() - 1] == 'x')
            {
                r_x_ind.insert(i);
                int c = 1;
                
                if(r_operands[i].size() - 1 > 0){
                    c = stoi(r_operands[i].substr(0, (r_operands[i]).size() - 1));
                }
                

                if(r_operators[i] == "-")
                {
                    c *= -1;
                }

                r_x_count += c;
            }
        }
        
        // cout<<"r_x_count "<<r_x_count<<endl;
        
        // Shift all the constants on the left hand side to the right hand side
        // meaning we flip the sign
        int result = 0;
        
        for(int i = 0; i < l_operators.size(); i++)
        {
            int sign = 1;
            if(l_operators[i] == "+")
                sign = -1;
            if(i < l_operands.size() && l_x_ind.find(i) == l_x_ind.end())
                result += stoi(l_operands[i])*sign;
        }
        // cout<<"result "<<result<<endl;
    

        // cout<<"result "<<result<<endl;
        
        for(int i = 0; i < r_operators.size(); i++)
        {
            int sign = 1;
            if(r_operators[i] == "-")
                sign = -1;
            if(i < r_operands.size() && r_x_ind.find(i) == r_x_ind.end())
                result += stoi(r_operands[i])*sign;
        }
        
        // cout<<"result "<<result<<endl;


        
        // cout<<"result "<<result<<endl;
        
        if(r_x_count == l_x_count)
        {
            // Infinite solutions
            if(result == 0)
            {
                return "Infinite solutions";
            }
            
            // No solution
            else
            {
                return "No solution";
            }
        }
    
        int X = l_x_count - r_x_count;
        result /= X;
        
        string s = to_string(result);

        return "x=" + s;
    }
};
