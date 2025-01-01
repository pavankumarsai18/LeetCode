class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '1') totalOnes++;
        }
        int numOnesSeen = 0;
        int maxScore = 0;
        for (size_t i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '1') numOnesSeen++;
            int subStringLen = (i + 1);

            int numZerosLeft = subStringLen - numOnesSeen;
            int numOnesRight = totalOnes - numOnesSeen;
            
            int score = numZerosLeft + numOnesRight;
            
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};
