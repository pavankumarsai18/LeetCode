class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {

        vector<vector<int>> result;


        vector<vector<int>> points;

        for(vector<int> & building: buildings)
        {
            points.push_back({building[0], -building[2]});
            points.push_back({building[1], building[2]});
        }

        auto compare = [](vector<int> & point1, vector<int> & point2)
        {
            if(point1[0] == point2[0]) return point1[1] < point2[1];
            return point1[0] < point2[0];
        };

        sort(points.begin(), points.end(), compare);
        

        map<int, int> heightMap;
        int prev = 0;
        heightMap[0] = 1;

        for(vector<int> & point: points)
        {
            if(point[1] < 0) heightMap[-point[1]]++;
            else {
                heightMap[point[1]]--;
                if(heightMap[point[1]] == 0) heightMap.erase(point[1]);
            }

            int cur = heightMap.rbegin()->first;
            if(cur != prev)
            {

                prev = cur;
                result.push_back({point[0], cur});
            }

        } 

        return result;


    }
};
