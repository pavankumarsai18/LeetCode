class Solution {
public:
    bool isPrefixAndSuffix(string & word1, string & word2) {
        if (word1.size() > word2.size()) return false;
        return (word2.find(word1) == 0 &&
                word2.rfind(word1) == word2.size() - word1.size());
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int numPrefixSuffixPair = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = (i+1); j < words.size(); ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    numPrefixSuffixPair++;
                }
            }
        }

        return numPrefixSuffixPair;
    }
};
