class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int canPlace = 0;
        const int length = flowerbed.size();
        
        if(n == 0)
            return true;
        if(length < n)
            return false;
        
        
        vector<int> newBed = {0};
        for(auto & item: flowerbed)
            newBed.push_back(item);
        newBed.push_back(0);
        
        for(int i = 1; i < length + 1;i++)
        {
            if(newBed[i-1] == 0 && newBed[i] == 0 && newBed[i+1] == 0)
            {
                newBed[i++] = 1;
                canPlace++;
            }
        }
        
        return (canPlace >= n);
    }
};
