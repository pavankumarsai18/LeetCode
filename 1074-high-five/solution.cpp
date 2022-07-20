class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) 
    {
        unordered_map<int, priority_queue<int>> studentScores;
        vector<vector<int>> ans;
        const int numItems = 5;
        
        for(int i = 0; i < items.size(); i++)
        {
            int id    = items[i][0];
            int score = items[i][1];
            
            studentScores[id].push(score);
        }
        
        
        for(auto & [id, scores]: studentScores)
        {
            int average = 0;
            
            for(int numPopped = 0; numPopped < numItems; numPopped++)
            {
                average += scores.top(); scores.pop();
            }
            
            average /= numItems;
            
            ans.push_back({id, average});
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
        
        
    }
};
