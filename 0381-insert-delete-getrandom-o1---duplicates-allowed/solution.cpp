class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> indexMap;
    vector<int> indexList;
public:
    RandomizedCollection() {
        srand(time(0));
    }
    
    bool insert(int val) {

        bool notPresent = indexMap.find(val) == indexMap.end();

        if(notPresent) {
            indexMap[val] = unordered_set<int>();
        }


        indexList.push_back(val);
        indexMap[val].insert(indexList.size() - 1);

        return notPresent;
        
    }
    
    bool remove(int val) {
        bool present = indexMap.find(val) != indexMap.end();

        if (!present) return false;

        int lastElement = indexList.back();
        const int curSize = indexList.size();
        if (lastElement == val) {
            indexMap[val].erase(curSize - 1);
        } else {
            int valIdx = *indexMap[val].begin();

            indexMap[val].erase(valIdx);
            indexMap[lastElement].erase(curSize - 1);
            indexMap[lastElement].insert(valIdx);

            swap(indexList[valIdx], indexList[curSize - 1]);
        }

        if (indexMap[val].size() == 0) indexMap.erase(val);
        indexList.pop_back();

        return present;
    }
    
    int getRandom() {

        int randIdx = rand() % indexList.size();

        return indexList[randIdx];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
