class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
        if(candies.size()%2 != 0)
            return 0;
        
        int result = 0;
        unordered_map<int, int>kind_count;
        for(int i = 0; i < candies.size(); i++)
        {
            auto itr = kind_count.find(candies[i]);
            if( itr == kind_count.end())
            {
                kind_count[candies[i]] =  1;
                result ++;
            }
        }
        if(result < candies.size()/2)
            return result;
        return candies.size()/2;
        // 1 1 2 2 2 3 3 3 4 4
        // total length = 10
        // A should get 5
        // B should get 5
        // A should get atleast one candy from the odd ones
        // A = 2 3 _ _ _
        // A should get atleast one candy from even ones
        // A = 2 3 1 4 _
        // remaining candies are 1 2 2 3 3 4
        // take 2
        // A = 2 3 1 4 2 ==> A = 4
        
        
        // 1 1 1 2 2 3 ==>hash map 3 * 1 + 2 * 2 + 1 * 3
        // total length = 6
        // A = 3
        // B = 3
        
        // A = 1 3
        
        
        // candies = a1*x1 + a2*x2 + a3*x3 ... + an*xn
        // a1 + a2 + a3 ... + an = length
        // length(A) = (a1 + a2 + a3 + ..... + an)/2
        // A = A1*x1 + A2* x2 ... + An*xn
        // A1 + A2 + A3 ... + An = length(candies)/2
        // we want to minimize the number of zeros in A1
        // constraints
        // Ai <= ai for all i >= 1 and i <= n
        
        // greedy stratergy we take atleast one candy which has odd number of candies
        // we do this bacuse taking one cady from odd ones reduces it 
        // to even number of candies and we get a candy of one type
        // then we go through all the even candies and take one
        // we do this till the length of A = length(candies)/2
        
        //1 1 3 2
        // 1 --> 2
        // 3 --> 1
        // 2 --> 1
        // 1 1 2 2 3 4 5 5 5 5
        // 1 2 3 4 5
        // 
        
        // 1 --> 2
        // 2 --> 1
        // 3 --> 1
//         int result_length = 0;
//         int different_candies = 0;
//         int count = 0;
//         unordered_map<int, int> result_distr;
        
//         while(result_length < candies.size()/2)
//         {
//             for(auto itr = kind_count.begin(); itr != kind_count.end(); itr++)
//             {
//                 //cout<<itr->first<<" "<<itr->second<<endl;
                
//                 if(itr->second%2 == 1)
//                 {
                    
//                     itr->second--;
                    
//                     auto itr_ = result_distr.find(itr->first);
//                     if(itr_ == result_distr.end())
//                     {
//                         result_distr[itr->first] = 1;
//                         different_candies++;
//                     }
//                     else
//                     {
//                         result_distr[itr->first]++;
//                     }
//                     result_length++;
//                     //cout<<"rl "<<result_length<<endl;
//                     //cout<<(result_length==(candies.size()/2))<<endl;
//                     if(result_length == candies.size()/2)
//                         break;
//                 }
//                 if(itr->second%2 == 0 && itr->second != 0 && count != 0)
//                 {
//                     itr->second--;
//                     auto itr_ = result_distr.find(itr->first);
//                     if(itr_ == result_distr.end())
//                     {
                        
//                         result_distr[itr->first] = 1;
//                         different_candies++;
//                     }
//                     else
//                     {
//                         result_distr[itr->first]++;
//                     }
//                     result_length++;
//                     //cout<<"rl "<<result_length<<endl;
//                     //cout<<(result_length==(candies.size()/2))<<endl;
//                     if(result_length == candies.size()/2)
//                         break;
//                 }
                
//             }
//             count ++;
//         }
        //return different_candies;
        
    }
};
