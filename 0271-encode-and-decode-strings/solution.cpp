class Codec {
private:
    const char delimiter = '#';
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";
        // Length of string + Delimiter + String
        for (int i = 0; i < strs.size(); ++i) {
            ans += to_string(strs[i].size()) + delimiter + strs[i];
        }

        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int idx = 0;
        while (idx != s.size()) {
            string strLen = "";
        
            while (idx < s.size() && '0' <= s[idx] <= '9')
            {
                strLen += s[idx];
                idx++;
                if (idx < s.size() && s[idx] == this->delimiter) {
                    idx++;
                    break;
                }
            }

            int length = stoi(strLen);
            ans.push_back(s.substr(idx, length));

            idx += length;
        }

        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
