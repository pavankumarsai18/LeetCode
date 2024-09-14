class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        if (n == 1 && flowerbed.size() == 1 && flowerbed[0] == 0) return true;
        int numPlanted = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (i == 0 && i + 1 < flowerbed.size() && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                numPlanted++;
            } else if (i != 0 && i != flowerbed.size() - 1 
                        && flowerbed[i] == 0
                        && flowerbed[i - 1] == 0 
                        && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                numPlanted++;
            } else if (i == flowerbed.size() - 1 && i - 1 >= 0 && flowerbed[i] == 0 && 
                flowerbed[i - 1] == 0) {
                flowerbed[i] = 1;
                numPlanted++;
            }

            if (numPlanted == n) return true;
        }

        return false;
    }
};
