class RandomizedSet {
private:
    int capacity;
    int numDeleted;
    int size;
    unordered_map<int, pair<int, bool>> num_index;
    unordered_map<int, int> index_num;
    unordered_set<int> s;
    
public:
    RandomizedSet() 
    {
        srand(time(0));
        
        num_index = unordered_map<int, pair<int, bool>>();
        index_num = unordered_map<int, int>();
        s = unordered_set<int>();
        
        size = 0;
        capacity = 1;
        numDeleted = 0;
    }
    
    bool insert(int val) 
    {
        // cout<<"In insert "<<endl;

        if(s.find(val) != s.end())
        {
            return false;
        }
        
        
        s.insert(val);
        index_num[size] = val;
        num_index[val] = {size, false}; // is deleted = false
        size++;
        
        if(size >= capacity)
        {
            int index = 0;
            num_index.clear();
            index_num.clear();
            for(auto itr = s.begin(); itr != s.end(); itr++)
            {
                num_index[*itr] = {index, false}; // is delteed = false
                index_num[index] = *itr;
                index++;
            }
            size = num_index.size();
            capacity *= 2;
        }
        
//         for(auto itr: num_index)
//         {
//             cout<<itr.first<<"->"<<itr.second.first<<","<<itr.second.second<<endl;
//         }
//         cout<<"-----\n";

//         for(auto itr: index_num)
//         {
//             cout<<itr.first<<"->"<<itr.second<<endl;
//         }
        
//         cout<<"size = "<<size<<endl;

        return true;
        
    }
    
    bool remove(int val) 
    {
        if(s.find(val) == s.end())
        {
            return false;
        }
        
        pair<int, bool> p = num_index[val];
        num_index[val] = {p.first, true}; // set deleted to true
        s.erase(val);
        numDeleted++;
        size--;
        if(numDeleted >= capacity/2)
        {
            int index = 0;
            num_index.clear();
            index_num.clear();
            for(auto itr = s.begin(); itr != s.end(); itr++)
            {
                num_index[*itr] = {index, false}; // is deleted = false
                index_num[index] = *itr;
                index++;
            }
            numDeleted = 0;
            capacity = capacity/2; 
            size = num_index.size();
        }
        
        // cout<<"In remove "<<endl;
        // for(auto itr: num_index)
        // {
        //     cout<<itr.first<<"->"<<itr.second.first<<","<<itr.second.second<<endl;
        // }
//         cout<<"-----\n";
//         for(auto itr: index_num)
//         {
//             cout<<itr.first<<"->"<<itr.second<<endl;
//         }
        
        // cout<<"size = "<<size<<endl;
        return true;

        
        
    }
    
    int getRandom() 
    {
        
        
        int index = rand()%index_num.size();
        while(num_index[index_num[index]].second == true)
        {
            index = rand()%index_num.size();
        }
        
        return index_num[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
