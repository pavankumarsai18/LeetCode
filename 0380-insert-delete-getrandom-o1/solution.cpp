class RandomizedSet {
private:
    vector<int> numList;
    unordered_map<int, int> numIndex;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        bool found = numIndex.find(val) != numIndex.end();

        numList.push_back(val);
        numIndex[val] = numList.size() - 1;
        
        return !found;
    }
    
    bool remove(int val) {

        bool found = numIndex.find(val) != numIndex.end();

        if (!found) return found;

        
        int index = numIndex[val];
        int lastElement = numList.back();
        numIndex[lastElement] = index;

        swap(numList[index], numList[numList.size()-1]);

        numList.pop_back();
        numIndex.erase(val);

        return found;
    }
    
    int getRandom() {

        int randIndex = rand() % numList.size();

        return numList[randIndex];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
