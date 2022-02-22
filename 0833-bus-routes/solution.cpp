// class Solution {
// private:
//     int BFS(const int & source, const int & target, unordered_map<int, bool> & vertices, unordered_map<int, vector<pair<int, int>>> & adjList)
//     {
        
//         unordered_map<int, pair<int, int>> parents;
//         list<int> queue;
        
//         vertices[source] = true;
        
//         queue.push_back(source);
        
//         while(queue.size())
//         {
//             // cout<<queue.size()<<endl;
//             int s = queue.front();
//             queue.pop_front();
//             cout<<"s "<<s<<": ";
//             for(int i = 0; i < adjList[s].size(); i++)
//             {
//                 pair<int, int> edge = adjList[s][i];
                
//                 if(vertices[edge.first] == false)
//                 {
//                     cout<<edge.first<<" ";
//                     parents[edge.first] = pair<int, int>(s, edge.second);
//                     queue.push_back(edge.first);
//                     vertices[edge.first] = true;
//                 }
//             }
//             cout<<endl;

//         }
        
//         // for(auto itr = parents.begin(); itr != parents.end(); itr++)
//         // {
//         //     cout<<itr->first<<" ("<<(itr->second).first<<","<<(itr->second).second<<")"<<endl;
//         // }
        
//         int result = -1;
//         unordered_set<int> routes;
//         if(vertices[target])
//         {
//             int curStop = target;
//             if(parents[curStop].first == source)
//                 return 1;
//             while(parents[curStop].first != source)
//             {
//                 cout<<parents[curStop].first<<", "<<parents[curStop].second<<endl;
//                 // cout<<"in here\n";
//                 routes.insert(parents[curStop].second);
//                 curStop = parents[curStop].first;
//             }
            
//             return routes.size();
//         }
//         return result;
        
//     }
// public:
//     int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
//     {
//         // Graph
//         // number each edge with the bus rout
//         // do a dfs from spource to target and then find the 
//         if(source == target)
//             return 0;
        
//         unordered_map<int, bool> vertices;
//         unordered_map<int, vector<pair<int, int>> > adjList;
//         for(auto & route: routes)
//         {
//             std::sort(route.begin(), route.end());
//             for(auto & stop: route)
//             {
//                 vertices[stop] = false;
//                 adjList[stop] = vector<pair<int, int>>();
//             }
//         }
        
//         for(int j = 0; j < routes.size(); j++)
//         {
//             for(int i = 0; i < routes[j].size(); i++)
//             {
//                 int stop = routes[j][i];
//                 if(i != routes[j].size() - 1)
//                 {
//                     pair<int, int> p;
//                     p.first = routes[j][i+1];
//                     p.second = j;
//                     adjList[stop].push_back(p);
//                 }
//                 else
//                 {
//                     pair<int, int> p;
//                     p.first = routes[j][0];
//                     p.second = j;
//                     adjList[stop].push_back(p);
//                 }
//             }
//         }
        
        
// //         for(auto itr = adjList.begin(); itr != adjList.end(); itr++)
// //         {
// //             cout<<itr->first<<": ";
// //             for(int i = 0; i < (itr->second).size(); i++)
// //             {
// //                 cout<<"("<<(itr->second)[i].first<< ", "<<(itr->second)[i].second<<")"<<" ";
// //             }
// //             cout<<endl;
// //         }
//         return BFS(source, target, vertices, adjList);
        
        
        
//     }
// };

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        map<int, vector<int>> m;
        
        for (int i=0; i<routes.size(); i++)
        {
            for (int j=0; j<routes[i].size(); j++)
            {
                if (m.find(routes[i][j]) == m.end())
                {
                    vector<int> temp;
                    temp.push_back(i);
                    m[routes[i][j]] = temp;
                }
                else
                {
                    m[routes[i][j]].push_back(i);
                }
            }
        }
        
        set<int> visitedStops, visitedBus;
        queue<int> q;
        
        q.push(source);
        visitedStops.insert(source);
        
        int level = 0;
        
        while (!q.empty())
        {
            int size = q.size();
            
            for (int i=0; i<size; i++)
            {
                int stop = q.front();
                q.pop();
                
                if (stop == target)
                    return level;
                
                vector<int> buses = m[stop];
                for (int j=0; j<buses.size(); j++)
                {
                    if (visitedBus.find(buses[j]) != visitedBus.end())
                        continue;
                    
                    for (int k=0; k<routes[buses[j]].size(); k++)
                    {
                        if (visitedStops.find(routes[buses[j]][k]) == visitedStops.end())
                        {
                            visitedStops.insert(routes[buses[j]][k]);
                            q.push(routes[buses[j]][k]);
                        }
                        else
                        {
                            continue;
                        }
                    }
                    visitedBus.insert(buses[j]);
                }
            }
            level++;
        }
        
        return -1;
    }
};
