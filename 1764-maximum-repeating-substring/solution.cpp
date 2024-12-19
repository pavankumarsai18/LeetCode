class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string repeat = word;

        while (sequence.find(repeat) != string::npos) {
            count++;
            repeat += word;
        }

        return count;
    }
};
