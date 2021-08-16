class Solution {
private:
    unordered_map<string, string> Encode;
    unordered_map<string, string> Decode;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        srand(time(0));
        
        string shortUrl = "";
        
        do
        {
            int randsize = rand()%longUrl.size();
            while(shortUrl.size() < randsize)
            {
                int lowercase = rand()%2;
                int start = 97;
                if(lowercase)
                    start = 65;

                shortUrl += (rand()%26) + start;
            }
            
        }while(Decode.find(shortUrl) != Decode.end());
        
        Encode[longUrl] = shortUrl;
        Decode[shortUrl] = longUrl;
        
        return shortUrl;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {   
        return Decode[shortUrl];   
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
