class Solution {
public:
    void print(queue<string> Q)
    {
        cout<<"QUEUE: ";
        while(Q.size())
        {
            cout<<Q.front()<<" ";
            Q.pop();
        }
        cout<<endl;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        
        // create a graph
        // do bfs
        
        unordered_set<string> words;
        bool beginWordExists = true;
        for(auto & word: wordList)
            words.insert(word);
        
        if(words.find(beginWord) == words.end())
        {
            beginWordExists = false;
            words.insert(beginWord);
        }

        unordered_map<string, vector<string>> adjList;

        for(auto & word:words)
        {
            adjList[word] = vector<string>();

            string newWord = word;

            for(int i = 0; i < word.size(); i++)
            {
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    newWord[i] = ch;
                    if(words.find(newWord) != words.end() && newWord != word)
                    {
                        adjList[word].push_back(newWord);  
                    }
                }
                newWord[i] = word[i];
            }
        }
        
        // for(auto & [word, neighbors]: adjList)
        // {
        //     cout<<word<<": ";
        //     for(auto & neighbor: neighbors)
        //         cout<<neighbor<<" ";
        //     cout<<endl;
        // }
        
        
        unordered_set<string> visited;
        
        unordered_map<string, int> dist;
        dist[beginWord] = 0;
        
        queue<string> Q;
        Q.push(beginWord);
        visited.insert(beginWord);

        while(Q.size())
        {

            string word = Q.front(); Q.pop();
            

            for(auto & neighbor: adjList[word])
            {
                
                if(visited.find(neighbor) == visited.end())
                {
                    visited.insert(neighbor);

                    Q.push(neighbor);
                    dist[neighbor] = dist[word] + 1;

                }
                if(neighbor == endWord)
                    break;
            }

        }
        
        if(visited.find(endWord) == visited.end())
            return 0;
        
        return dist[endWord]+1;
        
        
    }
};
