class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) 
    {
        int size = 0;
        for(int i = 0; i < nums.size() -1; i+=2)
        {
            size += nums[i];
        }
        
        vector<int> result = vector<int>(size);
        int a = 0;
        for(int i = 0; i < nums.size() - 1;i += 2)
        {
            int freq = nums[i];
            int val = nums[i+1];
            for(int j = 0; j < freq; j++){
                result[a] = val;
                a++;
            }
        }
        return result;
    }
};
