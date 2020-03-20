class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        // need to maintain the next item for each list
        // and also the length of each list
        // need O(1) for accessing the next item so use a unordered_map
        // can use a vector index to map to a particular index making it O(1)
        
        unordered_map<int,int> nextElement_index;
        unordered_map<int, stack<int>> arithmeticSequences;
        
        for(int i = 0; i < arr.size(); i++)
        {
            auto itr = nextElement_index.find(arr[i]);
            
            if(itr == nextElement_index.end())
            {
                nextElement_index[arr[i]] = i;
                auto Itr = arithmeticSequences.find(i);
                if(Itr == arithmeticSequences.end())
                {
                    stack<int> s;
                    s.push(arr[i]);
                    arithmeticSequences[i] = s;
                    nextElement_index[arr[i] + difference] = i;
                }
                else
                {
                    int t = arithmeticSequences[i].top();
                    if(t + difference == arr[i])
                    {
                        arithmeticSequences[i].push(arr[i]);
                    }
                }
                nextElement_index[arr[i] + difference] = i;
            }
            
            else
            {
                int ind = nextElement_index[arr[i]];
                
                int t = arithmeticSequences[ind].top();
                if(t + difference == arr[i])
                    arithmeticSequences[ind].push(arr[i]);
                
                nextElement_index[arr[i] + difference] = ind;
            }
        }
    
        int maxLength = 0;
        
        for(auto itr = arithmeticSequences.begin(); itr != arithmeticSequences.end(); itr++)
        {
            if(maxLength < (itr->second).size())
            {
                maxLength = (itr->second).size();
                
                // while((itr->second).empty() == false)
                // {
                //     cout<<itr->second.top()<<" ";
                //     itr->second.pop();
                // }
                // cout<<endl;
            }
        }
        
        return maxLength;
//         cout<<arr[max_ind]<<endl;
//         int val = arr[max_ind];
//         while(val <= max)
//         {
//             cout<<val<<" ";
//             val += difference;
//         }
//         cout<<endl;
        
        
        
        
        
        
        
        // USE a STACK like obj
        
        // O(n^2)
        
//         int max_length = 0;
//         unordered_set<int> S;
//         for(int i = 0; i < arr.size(); i++)
//         {
//             int len = 1;
            
//             int val = arr[i];
            
//             int j = i + 1;
//             auto itr = S.find(j);
//             if(arr.size() - j < max_length || itr != S.end())
//                 continue;
            
//             while(j < arr.size())
//             {
//                 if(arr[j] == val + difference)
//                 {
//                     auto itr = S.find(j);
//                     if(itr != S.end())
//                         break;
                    
//                     S.insert(j);
//                     len++;
//                     val += difference;
//                 }
//                 j++;
//             }
            
//             if(max_length < len)
//             {    
//                 max_length = len;
            
//             }
//         }
        
//         return max_length;
        
    }
};
