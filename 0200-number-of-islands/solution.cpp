class UnionFind{
private:
    unordered_map<int, int> item_index;
    int size;
    int numGroups;
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind()
    {
        size = 0;
        numGroups = 0;
    }
    
    void addItem(int item)
    {
        // cout<<"\t\taddItem "<<item<<endl;
        item_index[item] = size;
        parent.push_back(size++);
        rank.push_back(0);
        numGroups++;
        // cout<<"\t\tnumGroups "<<numGroups<<endl;
    }
    
    bool has(int item)
    {
        return item_index.find(item) != item_index.end();
    }
    int findItem(int item)
    {
        if(item_index.find(item) != item_index.end())
            return -1;
        
        int index = item_index[item];
        return find(index);
    }
    
    int find(int index)
    {
        if(parent[index] != index)
        {
            parent[index] = find(parent[index]);
        }
        return parent[index];
    }
    
    void unionItem(int item1, int item2)
    {
        // cout<<"\t\tunion item "<<item1<<" "<<item2<<endl;
        int index1 = item_index[item1];
        int index2 = item_index[item2];
        
        Union(index1, index2);
    }
    
    void Union(int index1, int index2)
    {
        int group1, group2;
        group1 = find(index1); group2 = find(index2);
        // cout<<"\t\tgroup1 "<<group1<<" group2 "<<group2<<endl;
        if(group1 != group2)
        {
            if(rank[group1] < rank[group2])
            {
                swap(group1, group2);
            }
            
            parent[group2] = group1;
            rank[group1]++;
            numGroups--;
        }
        // cout<<"\t\t"<<numGroups<<endl;
    }
    
    
    int getNumGroups()
    {
        return numGroups;
    }
    
};


class Solution {

public:
    int numIslands(vector<vector<char>>& grid) 
    {
        
        UnionFind islands = UnionFind();
        
        const int numRows = grid.size();
        const int numCols = grid[0].size();
        
        auto isValid = [&numRows, &numCols](int r, int c){return (0 <= r && r < numRows) && (0 <= c && c < numCols);};
        
        auto hash = [&numRows, &numCols](int r, int c){return (r*(numCols) + c);};
        
        vector<vector<int>> steps = {{-1,0},{1,0},{0,1},{0,-1}};
        
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < numCols; j++)
            {
                if(grid[i][j] == '1')
                {
                    // cout<<i<<" "<<j<<endl;
                    if(!islands.has(hash(i, j)))
                    {
                        islands.addItem(hash(i, j));
                    }
                    for(auto & step: steps)
                    {
                        int di, dj;
                        di = step[0]; dj = step[1];

                        if(isValid(i+di, j+dj) && grid[i+di][j+dj] == '1')
                        {
                            // cout<<"\t "<<i+di<<" "<<j+dj<<endl;
                            
                            if(!islands.has(hash(i+di, j+dj)))
                            {
                                islands.addItem(hash(i+di, j+dj));
                            }
                            islands.unionItem(hash(i, j), hash(i+di,j+dj));
                        }

                    }
                }
            }
        }
        
        return islands.getNumGroups();
        
    }
};
