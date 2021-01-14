class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        unordered_map<char, int> char_time;
        int maxTime = 0;
        
        for(int i = 0; i < releaseTimes.size(); i++)
        {
            int timeTaken;
            if(i == 0)
            {
                timeTaken = releaseTimes[0];
            }
            else
            {
                timeTaken = releaseTimes[i] - releaseTimes[i - 1];
            }
            
            if(maxTime < timeTaken)
                maxTime = timeTaken;
            
            auto itr = char_time.find(keysPressed[i]);
            
            if(itr == char_time.end())
            {
                char_time[keysPressed[i]] = timeTaken;    
            }
            else
            {
                if(itr->second < timeTaken)
                    itr->second = timeTaken;
            }
        }
        
        string resultStr = "";
        
        for(auto itr = char_time.begin(); itr != char_time.end(); itr++)
        {
            if(itr->second == maxTime)
            {
                resultStr += itr->first;
            }
        }
        
        char result = resultStr[0];
        for(auto & c: resultStr)
        {
            if(result < c)
                result = c;
        }
        
        return result;
    }
};
