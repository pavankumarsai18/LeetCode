class Solution {
private:
    vector<string> putBeside(string & p)
    {
        vector<string> result;
        result.push_back("()"+p);
        for(int i = 0; i < p.size(); i++)
        {
            if(p[i] == ')')
            {
                
                string s = p.substr(0, i+1) + "()";
                if(i + 1 < p.size())
                {
                    s += p.substr(i+1, p.size() - (i+1));
                }
                
                result.push_back(s);
            }
        }
        
        return result;
    }
    
    vector<string> putInside(string & p)
    {        
        vector<string> result;
        for(int i = 0; i < p.size(); i++)
        {
            if(p[i] == '(')
            {
                string s = p.substr(0, i+1) + "()";
                if(i + 1 < p.size())
                {
                    s += p.substr(i+1, p.size() - (i+1));
                }
                
                result.push_back(s);
            }
        }
        
        return result;
    }
    
public:
    vector<string> generateParenthesis(int n) 
    {
        if(n <= 0)
            return vector<string>();
        
        
        vector<string> result;
        result.push_back("()");
        
        for(int i = 2; i <= n; i++)
        {
            // Generate Parenthesis
            unordered_set<string> temp;
            
            
            for(auto & p: result)
            {
                vector<string> appended = putBeside(p);
                vector<string> embedded = putInside(p);
                
                for(auto & s: appended)
                {
                    temp.insert(s);
                }
                for(auto & s: embedded)
                {
                    temp.insert(s);
                }
                
                
            }
            
            result = vector<string>();
            for(auto &s: temp)
                result.push_back(s);
            
        }
        
        return result;
    }
};
