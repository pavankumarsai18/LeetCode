class Solution {
public:
    string getCharCountString(const string & str) {
        vector<int> charCount(26, 0);
        for(int i = 0; i < str.size(); ++i) {
            charCount[str[i] - 'a']++;
        }

        string ans = "";

        for(int i = 0; i < charCount.size(); ++i) {
            ans += to_string(charCount[i]) + " ";
        }

        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> anagramMap;

        for(int i = 0; i < strs.size(); i++) {
            string charCountStr = getCharCountString(strs[i]); 
            if(anagramMap.find(charCountStr) == anagramMap.end()) {
                anagramMap[charCountStr] = {};
            }
            anagramMap[charCountStr].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto itr = anagramMap.begin(); itr != anagramMap.end(); itr++) {
            ans.push_back(itr->second);
        }

        return ans;
    }
};
