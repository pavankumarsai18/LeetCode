class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        const int n = s.size();

        for(int i = 0; i < n; ++i) {

            string word = "";
            while(i < n && s[i] != ' ') {
                word += s[i++];
            }

            if(word.size())
                words.push_back(word);

        }

        string ans = "";
        for(int i = words.size() - 1; i >= 0; --i) {
            ans += words[i];

            if (i != 0) {
                ans += " ";
            }
        }
        return ans;
    }
};
