class Solution {
public:
    // set<string> result;
    // int count = 0;
    vector<string> letterCasePermutation(string S) 
    {
        vector<int> char_index;
        
        for(int i = 0; i < S.size();i++)
        {
            if(S[i] >= 'a' && S[i] <= 'z' || S[i] >= 'A' && S[i] <= 'Z')
            {
                char_index.push_back(i); 
            }
        }
        
        vector<string> result;
        result.push_back(S);
        
        for(int i = 0; i < char_index.size();i++)
        {
            int size = result.size();
            for(int j = 0; j < size;j++)
            {
                string temp = result[j];
                if(islower(temp[char_index[i]]))
                {
                    temp[char_index[i]] = toupper(temp[char_index[i]]);
                    result.push_back(temp);
                }
                else
                {
                    temp[char_index[i]] = tolower(temp[char_index[i]]);
                    result.push_back(temp);
                }
            }
        }
        return result;
        
        
        
        
        
//         vector<string> result_arr;
        
//         result.insert(S);
//         auto all_permut = Permut(S);
        
//         for(auto itr = all_permut.begin(); itr != all_permut.end();itr++)
//         {
//             result_arr.push_back(*itr);
//         }
//         //cout<<count;
//         return result_arr;
    }
    
//     set<string> Permut(string S)
//     {
//         //count ++;
//         auto itr = result.find(S);
//         if(itr == result.end())
//             return result;
        
//         result.insert(S);
//         for(int i = 0; i < S.size(); i++)
//         {
//             if((S[i]>='a'&& S[i]<='z') || (S[i]>='A' && S[i]<='Z'))
//             {
//                 if(S[i] >= 'a' && S[i] <= 'z')
//                 {
//                     auto temp = S;
//                     temp[i] = toupper(temp[i]);
//                     auto itr = result.find(temp);
//                     if(itr == result.end())
//                     {
//                         result.insert(temp);
//                         set<string> result_ = Permut(temp);
//                         for(auto itr = result_.begin(); itr != result_.end();itr++)
//                         {
//                             result.insert(*itr);
//                         }     
//                     }
//                 }
//                 else if(S[i] >= 'A' && S[i] <= 'Z')
//                 {
//                     auto temp = S;
//                     temp[i] = tolower(temp[i]);
//                     auto itr = result.find(temp);
//                     if(itr == result.end())
//                     {
//                         result.insert(temp);
//                         set<string> result_ = Permut(temp);
//                         for(auto itr = result_.begin(); itr != result_.end();itr++)
//                         {
//                             result.insert(*itr);
//                         }     
//                     }
//                 }
//             }
//         }
        
//         return result;
//     }
};
