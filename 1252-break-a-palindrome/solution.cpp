class Solution {
public:
    string breakPalindrome(string palindrome) {
        const int n = palindrome.size();
        int left, right;
        left = 0; right = n - 1;
        
        
        while(left < right)
        {
            if(palindrome[left] != 'a')
            {
                palindrome[left] = 'a';
                return palindrome;
            }
            left++;
            right--;
        }
        
        left = 0; right = n - 1;
        while(left < right)
        {
            if(palindrome[right] == 'a')
            {
                palindrome[right] = 'b';
                break;
            }
            left++; right--;
        }
        
        left = 0; right = n - 1;
        
        while(left < right)
        {
            if(palindrome[left] != palindrome[right])
            {
                return palindrome;
            }
            left++; right--;
        }
        
        return "";
        
        
    }
};
