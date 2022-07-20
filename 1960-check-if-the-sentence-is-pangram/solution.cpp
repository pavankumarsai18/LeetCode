class Solution {
public:
    bool checkIfPangram(string sentence) {
        int present = 0;
        const int target = ((1 << 26) - 1);
        for(int i = 0; i < sentence.size(); i++)
        {
            present |= (1 << (sentence[i] - 'a'));
        }
        
        return present == target;
        
    }
};
