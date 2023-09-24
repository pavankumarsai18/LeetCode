class Solution {
public:
    int findLongestChain(const string & word, const unordered_set<string> & wordSet, unordered_map<string, int> & memo) {

        if (memo.find(word) != memo.end()) 
            return memo[word];

        int ans = 1;

        const int len = word.size();

        for (int i = 0; i < len; ++i) {
            string newString = word.substr(0,i) + word.substr(i+1);
            
            if(wordSet.find(newString) != wordSet.end()) {
                int chainLength = findLongestChain(newString, wordSet, memo);
                chainLength++;
                ans = max(ans, chainLength);
            }
        
        }

        memo[word] = ans;
        return ans;
        
    }
    int longestStrChain(vector<string>& words) {
        // sort the words based on size
        // create a graph and find the maximum depth
        
        unordered_set<string> wordSet(words.begin(), words.end());

        unordered_map<string, int> memo;
        int maxChain = 0;
        for (const auto & word: words) {
            maxChain = max(maxChain, findLongestChain(word, wordSet, memo));
        }
    

        return maxChain;

    }
};
