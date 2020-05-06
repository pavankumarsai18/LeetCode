class Solution {
private:
    vector<int> original;
    vector<int> shuffled;
public:
    Solution(vector<int>& nums) {
        original = nums;
        shuffled = nums;
        srand(time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        shuffled = original;
        return shuffled;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        for(int i = shuffled.size()-1; i >= 0; i--)
        {
            int index = rand()%(i+1);
            swap(shuffled[index], shuffled[i]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
