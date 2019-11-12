class Solution {
public:
    vector<int> diStringMatch(string S) {
        
        //Wow Pavan!!!
        //Create a vector of size S.size() + 1 
        vector<int> result(S.size()+1);
        map<int, int> num_count;
        
        // first we start vector with 0 and then if we encounter a 
        // D we decrese it by 1 if we encounter an I we increse it by 1
        
        result[0] = 0;
        num_count[0] = 1;
        
        int min = 0;
        int max = 0;
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == 'D')
            {
                result[i+1] = result[i] - 1;
                if(result[i+1] < min)
                    min = result[i+1];
                auto itr = num_count.find(result[i+1]);
                if(itr != num_count.end())
                {
                    result[i+1] = min - 1;
                    if(result[i+1] < min)
                    min = result[i+1];
                    
                    num_count[result[i+1]] = 1;
                }
                else
                {
                    num_count[result[i+1]] = 1;
                }
            }
            else if (S[i] == 'I')
            {
                result[i+1] = result[i] + 1;
                if(max < result[i+1])
                    max = result[i+1];
                
                auto itr = num_count.find(result[i+1]);
                if(itr != num_count.end())
                {
                    result[i+1] = max + 1;
                    if(max < result[i+1])
                        max = result[i+1];
                    
                    num_count[result[i+1]] = 1;
                }
                else
                {
                    num_count[result[i+1]] = 1;
                }
            }
        }
        
        
        //Then we find the min element in the array and add it to all the elements
        //in the array
        min = result[0];
        for(int i = 0; i < result.size(); i++)
        {
            if(min > result[i])
                min = result[i];
        }
        
        
        //add the min element to the array
        if(min < 0)
        {
            min *= -1;
            for(int i = 0; i < result.size(); i++)
            {
                result[i] += min;
            }
        }
        return result;
    }
};
