class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        
        for(int i = 0; i < address.length(); i++)
        {
            if(address[i+1] != '.' && i < address.length() - 1)
            {
                result += address[i];
            }
            
            else if (address[i+1] == '.' && i < address.length() - 1)
            { 
                result += address[i];
                result += "[.]";
                i += 1;
            }
            else
            {
                result += address[i]; 
            }
                
        }
        return result;
    }
};
