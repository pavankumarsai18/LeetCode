class Solution {
private:
    // t2 = t2 - t1
    int getDiff(const string & t2, const string & t1)
    {
        int hour1, min1;
        int hour2, min2;
        
        string hour =  string(1, t1[0]) + t1[1];
        string min =  string(1, t1[3]) +  t1[4];
        
        hour1 = stoi(hour);
        min1 = stoi(min);
        
        hour = string(1, t2[0]) + t2[1];
        min =  string(1, t2[3]) +  t2[4];
        
        hour2 = stoi(hour);
        min2 = stoi(min);
        
        int diff = (hour2 - hour1)*60 + (min2 - min1);
        return diff;
    }
    
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) 
    {
        unordered_map<string, vector<string>> nameTimeMap;
        
        const int n = keyName.size();
        
        // Populate items into map
        for(int i = 0; i < n; i++)
        {
            if(nameTimeMap.find(keyName[i]) == nameTimeMap.end())
            {
                nameTimeMap[keyName[i]] = vector<string>();
            }
            
            nameTimeMap[keyName[i]].push_back(keyTime[i]);
        }
        
    
        vector<string> alertedNames;
        const int windowSize = 3;
        for(auto & [name, times]: nameTimeMap)
        {
            sort(times.begin(), times.end());

            for(int i = 0; i <= times.size() - windowSize; i++)
            {
                bool isAlerted = true;
                int startIndex = i;
                for(int j = i + 1; j < i + windowSize ; j++)
                {
                    int diff = getDiff(times[j], times[startIndex]);
                    if(diff > 60)
                    {
                        isAlerted = false;
                        break;
                    }
                }
                if(isAlerted == true)
                {
                    alertedNames.push_back(name);
                    break;
                }
            }
        }
        
        sort(alertedNames.begin(), alertedNames.end());
        return alertedNames;
        
    }
};
