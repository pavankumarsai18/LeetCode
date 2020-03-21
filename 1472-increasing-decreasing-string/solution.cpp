class Solution {
public:
    string sortString(string s) 
    {
        unordered_map<char, int> char_count;
        
        for(char c: s)
        {
            auto itr = char_count.find(c);
            if(itr == char_count.end())
                char_count[c] = 1;
            else
                char_count[c]++;
        }
        
        vector<char> V;
        for(auto itr = char_count.begin(); itr != char_count.end(); itr++)
        {
            V.push_back(itr->first);
        }
        
        sort(V.begin(), V.end());
        
        string result = "";
        do
        {
            // Pick the smallest character from s and append it to the result.
            if(char_count[V[0]] > 0){
                result += V[0];
                char_count[V[0]]--;
            }

            //Pick the smallest character from s which is greater than the last appended character to the result and append it.
            // Repeat step 2 until you cannot pick more characters.
            int i = 1;
            while(i < V.size() - 1)
            {
                if(char_count[V[i]] > 0){
                    result += V[i];
                    char_count[V[i]]--;
                }
                i++;
            }

            // Pick the largest character from s and append it to the result.
            if(char_count[V[V.size() - 1]] > 0)
            {
                result += V[V.size() - 1];
                char_count[V[V.size() - 1]]--;
            }

            //Pick the largest character from s which is smaller than the last appended character to the result and append it.
            // Repeat step 5 until you cannot pick more characters.
            i = V.size() - 1;
            while(i >= 0)
            {
                if(char_count[V[i]] > 0){
                    result += V[i];
                    char_count[V[i]]--;
                }
                i--;
            }
        }while(result.size() != s.size());
        
        return result;
    }
};
