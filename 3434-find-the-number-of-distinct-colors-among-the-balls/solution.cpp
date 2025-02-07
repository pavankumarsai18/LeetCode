class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> color_map;
        unordered_map<int, int> ball_color;
        for (int i = 0; i < queries.size(); ++i) {
            int ball = queries[i][0], color = queries[i][1];
            

            if (ball_color.find(ball) != ball_color.end()) {
                color_map[ball_color[ball]]--;
                if (color_map[ball_color[ball]] == 0) {
                    color_map.erase(ball_color[ball]);
                }

            }

            ball_color[ball] = color;
            color_map[ball_color[ball]]++;
            ans.push_back(color_map.size());
        }

        return ans;
    }
};
