class Solution {
public:
    int getScore(vector<int>& cardPoints, int k, int left, int right, unordered_map<string, int> & cache)
    {
        string key = to_string(left) + "," + to_string(right);
        
        if(cache.find(key) != cache.end())
        {
            return cache[key];
        }
        if(k == 0 || left > right)
        {
            return 0;
        }
        else if(k == 1)
        {
            return max(cardPoints[left], cardPoints[right]);
        }
        
    int leftScore = getScore(cardPoints, k-1, left+1, right, cache)  + cardPoints[left];
    int rightScore = getScore(cardPoints, k-1, left, right-1, cache) + cardPoints[right];
                
        cache[key] = max(leftScore, rightScore);
        return max(leftScore, rightScore);
        
    }
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n = cardPoints.size();
        int frontCards[k+1];
        int rearCards[k+1];
        frontCards[0] = rearCards[0] = 0;
        for(int i = 0; i < k; i++)
        {
            frontCards[i+1] = frontCards[i] + cardPoints[i];
            rearCards[i+1]  = rearCards[i]  + cardPoints[n-i-1];
        }
        
        int maxScore = 0;
        for(int i = 0; i <= k; i++)
        {
            int curScore = frontCards[i] + rearCards[k-i];
            maxScore = max(maxScore, curScore);
        }
        return maxScore;
    }
};
