class Solution {
public:
    string hashAnagram(string & str)
    {
        const int numChars = 26;
        int charCount[numChars] = {0};
        // Get the char count
        for(int i = 0; i < str.size(); i++)
        {
            charCount[str[i]-'a']++;
        }


        string result = "";
        // convert it into a string
        for(int i = 0; i < numChars; i++)
        {
            result += to_string(charCount[i]) + ',';
        }

        return result;
    }

    vector<vector<string>> groupAnagrams(vector<string>& words) 
    {
        unordered_map<string, vector<string>> map;
        
        
        for(int i = 0; i < words.size(); i++)
        {
            string hashValue = hashAnagram(words[i]);
            map[hashValue].push_back(words[i]);
        }
        
        vector<vector<string>> ans;
        
        for(auto & [hashVal, anagrams]: map)
            ans.push_back(anagrams);
        return ans;
        
        
    }
};
