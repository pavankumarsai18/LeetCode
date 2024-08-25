class Solution {
public:
    void countFrequencies(vector<int>& nums, unordered_map<int, int>& numCount) {
        for (int i = 0; i < nums.size(); ++i) {
            if (numCount.find(nums[i]) == numCount.end()) {
                numCount[nums[i]] = 0;
            }
            numCount[nums[i]]++;
        }
    }

    bool isEqual(unordered_map<int, int> & numCountA, unordered_map<int, int> & numCountB) {
        if (numCountA.size() != numCountB.size()) return false;
        
        for (const auto & [num, count] : numCountA) {
            if (numCountB.find(num) == numCountB.end() 
                || numCountB[num] != count) {
                return false;
            }
        }
        
        return true;
    }

    bool canBeEqual(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> numCountA;      
        unordered_map<int, int> numCountB;   

        countFrequencies(A, numCountA);
        countFrequencies(B, numCountB);

        return isEqual(numCountA, numCountB);
        

    }
};
