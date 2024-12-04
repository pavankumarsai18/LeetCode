class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str1Index = 0, str2Index = 0;

        while (str1Index < str1.size() && str2Index < str2.size()) {
            if (str1[str1Index] == str2[str2Index] ||
                str1[str1Index] + 1 == str2[str2Index] || 
                str1[str1Index] - 25 == str2[str2Index]) {
                    str2Index++;
            }
            str1Index++;
        }
        return str2Index ==  str2.size();
    }
};
