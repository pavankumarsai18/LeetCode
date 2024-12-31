class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int nimSum = 0;
        for (int p : piles) {
            nimSum ^= p;
        }
        return nimSum != 0;

    }
};
