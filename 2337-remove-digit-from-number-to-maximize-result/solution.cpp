class Solution {
public:
    string removeDigit(string number, char digit) 
    {
        // Find the most significat bit and
        // if the immediate next digit is greater than it we remove it
        // else continue
        string result = "";
        const int size = number.size();
        int removeIndex = -1;
        for(int i = 0; i < size; i++)
        {
            if(number[i] == digit)
            {
                removeIndex = i;
                if(i != size-1 && number[i+1] > digit)
                {
                    removeIndex = i;
                    break;
                } 
            }
        }
        
        if(removeIndex == -1)
            return number;
        result = number.substr(0, removeIndex) + number.substr(removeIndex+1);
        return result;
        
        
    }
};
