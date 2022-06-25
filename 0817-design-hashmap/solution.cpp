class MyHashMap {
public:
    vector<list<pair<int, int>>> hashTable;
    int size;
    int capacity;
    
    MyHashMap() 
    {
        size = 0;
        capacity = 1;
        for(int i = 0; i < capacity; i++)
        {
            hashTable.push_back(list<pair<int, int>>());
        }
    }
    void print()
    {
        for(int i = 0; i < capacity; i++)
        {
            for(auto item: hashTable[i])
            {
                cout<<item.first<<":"<<item.second<<" ";
            }
            if(hashTable[i].size() > 0)
                cout<<endl;
        }
    }
    void resize()
    {
        vector<list<pair<int, int>>> newHashTable;
        for(int i = 0; i < 2*capacity; i++)
        {
            newHashTable.push_back(list<pair<int, int>>());

        }
        for(int i = 0; i < capacity; i++)
        {
            for(auto pair: hashTable[i])
            {
                int key = pair.first;
                int val = pair.second;
                
                newHashTable[key%(2*capacity)].push_back({key, val});
            }
        }
        
        hashTable = newHashTable;    
        capacity *= 2;
    }
    void put(int key, int value) 
    {
        bool found = false;
        int index = key%capacity;
        for(auto & pair: hashTable[index])
        {
            if(pair.first == key)
            {
                found = true;
                pair.second = value;
            }
        }
        
        if(!found)
        {
            hashTable[index].push_back({key, value});
        }
        size++;
        if(size == capacity)
        {
            resize();
        }
    }
    
    int get(int key) 
    {
        int index = key%capacity;
        for(auto & pair: hashTable[index])
        {
            if(pair.first == key)
            {
                return pair.second;
            }
        }
        return -1;
    }
    
    void remove(int key) 
    {
        int index = key%capacity;
        auto it = hashTable[index].begin();
        for(; it != hashTable[index].end(); it++)
        {
            if(it->first == key)
            {
                break;
            }
        }
        if(it != hashTable[index].end())
        {
            hashTable[index].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
