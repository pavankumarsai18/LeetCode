class Solution {
public:
    vector<int> getCharCount(string & word) {
        vector<int> char_count(26, 0);
        for (int i = 0; i < word.size(); ++i) {
            char_count[word[i] - 'a']++;
        }
        return char_count;
    }

    vector<int> get_max_count(vector<int> & count1, vector<int> & count2) {
        vector<int> ans;
        if (count1.size() > count2.size()) {
            return get_max_count(count2, count1);
        }

        int min_length = count1.size();
        int max_length = count2.size();

        for (int i = 0; i < min_length; ++i) {
            ans.push_back(max(count1[i], count2[i]));
        }
        for (int i = min_length; i < max_length; ++i) {
            ans.push_back(count2[i]);
        }
        return ans;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        vector<int> max_words2_count;
        for (string & word: words2) {
            vector<int> word_count = getCharCount(word);
            max_words2_count = get_max_count(word_count, max_words2_count);   
        }

        for (string & word: words1) {
            vector<int> word_char_count = getCharCount(word);
            bool is_universal = true;
            for (int i = 0; i < word_char_count.size(); ++i) {
                if (word_char_count[i] < max_words2_count[i]) {
                    is_universal = false;
                    break;
                }
            }
            if (is_universal) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
