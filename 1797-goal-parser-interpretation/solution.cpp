class Solution {
public:
    string interpret(string command) 
    {
        string result = "";
                
        for(int i = 0; i < command.size(); i++)
        {
            
            if(command[i] == '(')
            {
                i++;
                if(i < command.size() && command[i] == ')')
                {
                    result += 'o';
                    continue;
                }
                
                while(i < command.size() && command[i] != ')')
                {

                    result += command[i];
                    i++;
                }
            }
            else if(command[i] != '(' && command[i] != ')' )
            {
                result += command[i];   
            }
        }
        
        return result;
    }
};
