
class AllOne 
{
private:
    map<int, unordered_set<string>> freqBucket;
    unordered_map<string, int> stringFreq;
public:
    AllOne() 
    {}
    
    void inc(string key) 
    {
        // cout<<"inc "<<key<<endl;
        auto itr = stringFreq.find(key);
        if(itr != stringFreq.end())
        {
            freqBucket[itr->second].erase(key);
            if(freqBucket[itr->second].empty()) freqBucket.erase(itr->second);
            itr->second++;
            freqBucket[itr->second].insert(key);
        }
        else
        {
            freqBucket[1].insert(key);
            stringFreq[key] = 1;
        }
    }
    
    void dec(string key) 
    {
        // cout<<"dec "<<key<<endl;

        auto itr = stringFreq.find(key);

        freqBucket[itr->second].erase(key);
        if(freqBucket[itr->second].empty()) freqBucket.erase(itr->second);
        itr->second--;
        
        if(itr->second == 0) stringFreq.erase(key);
        else freqBucket[itr->second].insert(key);

        
    }
    
    string getMaxKey() 
    {
        // cout<<"getMaxKey\n";

        if(stringFreq.empty()) return "";
        // cout<<*(freqBucket.rbegin()->second).begin()<<endl;
        return *(freqBucket.rbegin()->second).begin();
    }
    
    string getMinKey() 
    {
        // cout<<"getMinKey\n";
        
        if(stringFreq.empty()) return "";
        // cout<<*(freqBucket.begin()->second).begin()<<endl;
        return *(freqBucket.begin()->second).begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
