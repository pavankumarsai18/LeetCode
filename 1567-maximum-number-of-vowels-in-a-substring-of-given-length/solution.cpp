class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int numVowels, maxVowels, left, right;
        left = right = numVowels = maxVowels = 0;

        for(; right < k; ++right) {
            if (isVowel(s[right])) {
                ++numVowels;
            }
        }

        maxVowels = numVowels;

        for(; right < s.size(); ++right, ++left) {
            numVowels += (isVowel(s[right]) - isVowel(s[left]));

            maxVowels = max(maxVowels, numVowels);
        }

        return maxVowels;
    }
};
