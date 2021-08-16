class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue)    {
        int result = 0;
        int index = 0;
        
        if(ruleKey == "color")
            index = 1;
        else if(ruleKey == "name")
            index = 2;
        
        for(int i = 0; i < items.size(); i++)
        {
            if(items[i][index] == ruleValue)
                result += 1;
        }
        
        return result;
        
    }
};
