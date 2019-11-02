class Solution {
public:
    
    //al most done check again laet future pavan
    int numUniqueEmails(vector<string>& emails) {
        set<string> email;
        int at_count = 0;
        for(int j = 0; j < emails.size(); j++)
        {
            string result = "";
            for(int i = 0; i < emails[j].size(); i++)
            {
                 
                
                if(at_count == 0 && emails[j][i] == '.' && i+1 < emails[j].size() && emails[j][i+1] != '@')
                    ;             
                else if(emails[j][i] == '+')
                {
                    while(i < emails[j].size() && emails[j][i] != '@')
                        i++;
                    if(emails[j][i] == '@')
                    {
                        at_count++;
                        result += emails[j][i];
                    }
                }
                
                else
                {
                    if(emails[j][i] == '@')
                        at_count ++;
                    result += emails[j][i];
                }
                
            }
            at_count = 0;
            //cout<<result<<endl;                  
            email.insert(result);
        }
                                                       
        return email.size();
    }
};
