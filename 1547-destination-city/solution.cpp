class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> allNodes;

        for (auto & path: paths) {
            allNodes.insert(path[0]);
            allNodes.insert(path[1]);
        }

        for (auto & path: paths) {
            allNodes.erase(path[0]);
        } 


        return *allNodes.begin();


    }
};
