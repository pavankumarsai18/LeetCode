class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        // encoded[i] = arr[i] ^ arr[i+1]
        // arr[0] = 1
        // 0 = (arr[i]^encoded[i])^arr[i+1]
        // arr[i+1] = (arr[i]^encoded[i])^0
        
        vector<int> result;
        result.push_back(first);
        for(int i = 0; i < encoded.size(); i++)
        {
            result.push_back(result[result.size() - 1]^ encoded[i]);   
        }
        
        return result;
    }
};
