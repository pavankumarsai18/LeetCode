class Solution {
private:
    int calc(vector<int>& coor, vector<int>& fact)
    {
        int sum = 0;
        for(int i = 0; i < coor.size(); i++)
            sum += coor[i];
        int result = fact[sum];
        for(int i = 0; i < coor.size(); i++)
            result /= fact[coor[i]];
        
        return result;
    }
public:
    int numTilePossibilities(string tiles)
    {
       unordered_map<int, int> char_count;
        for(int i = 0; i < tiles.size(); i++)
        {
            auto itr = char_count.find(tiles[i]);
            if(itr == char_count.end())
                char_count[tiles[i]] = 1;
            else
                char_count[tiles[i]]++;
        }
    
        int arr[] = {0,0,0,0,0,0,0};
        // Given that tiles.length <= 7
        // So we can create a vector of size 7 and populate it with char_count titles
        // the ramaining must be populated with size = 0
        int i_ = 0;
        for(auto itr = char_count.begin(); itr != char_count.end(); itr++)
        {
            arr[i_] = itr->second;
          
            i_++;
        }
        
        vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040};
        int result = 0;
        for(int i = 0; i <= arr[0]; i++)
        {
            for(int j = 0; j <= arr[1]; j++)
            {
                for(int a = 0; a <= arr[2]; a++)
                {
                    for(int b = 0; b <= arr[3]; b++)
                    {
                        for(int c = 0; c <= arr[4];c++)
                        {
                            for(int d = 0; d <= arr[5]; d++)
                            {
                                for(int e = 0; e <= arr[6]; e++)
                                {
                                    vector<int> temp= {i, j, a, b, c, d, e};
                                    result += calc(temp, fact);
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return result - 1;
    }
};
