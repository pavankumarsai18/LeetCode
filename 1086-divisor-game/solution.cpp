class Solution {
private:
    unordered_map<int, bool> memo;
public:
    bool divisorGame(int n) {
        return (n & 1) == 0;
    }
};
