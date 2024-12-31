class Solution {
public:
    long long countVowels(string word) {
        long long sum_num_vowels = 0;
        long long n = word.size();
        for (int i = 0; i < n; ++i) {
            if (word[i] == 'a' ||
                word[i] == 'e' ||
                word[i] == 'i' ||
                word[i] == 'o' ||
                word[i] == 'u') 
            {
                sum_num_vowels += (n - i)*(i+1);            
            }
        }
        return sum_num_vowels;
    }
};
