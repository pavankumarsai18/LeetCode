class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {    
        int rolling_xor = 0;
        for (auto & num: derived) {
            rolling_xor ^= num;
        }
        return rolling_xor == 0;
    }
};
