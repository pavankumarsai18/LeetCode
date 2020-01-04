class Solution {
public:
    string simplifyPath(string path) 
    {
        // Stack
        
        // 1. if the top of the stack is '/' then we cannot insert another '/' on top
        // 2. ignore '.'
        // 3. if we encounter '..' then pop the stack
        
        deque<string> p;
        p.push_back("/");
        
        for(int i = 1; i < path.size(); i++)
        {
            if(path[i] == '/')
            {
                if(p.back() != "/")
                    p.push_back("/");
            }
            else
            {
                string temp = "";
                while(i < path.size() && path[i] != '/')
                {
                    temp += path[i];
                    i++;
                }
                if(temp == ".")
                    continue;
                else if(temp == "..")
                {
                    if(p.size() >= 2)
                    {
                        p.pop_back();
                        p.pop_back();
                    }
                }
                else
                {
                    p.push_back(temp);
                    p.push_back("/");
                }
            }
        }
        
        if(p.back() == "/" && p.size() > 1)
            p.pop_back();
        
        string P = "";
        while(p.size() != 0)
        {
            P += p.front();
            p.pop_front();
        }
        return P;
        
    }
};
