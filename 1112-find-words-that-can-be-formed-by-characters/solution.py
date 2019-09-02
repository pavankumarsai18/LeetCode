class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        result = 0
        for word in words:
            is_in = True
            c_n = {}
            for char in chars:
                if char in c_n:
                    c_n[char] += 1
                else:
                    c_n[char] = 1
            
            for c in word:
                if c in c_n:
                    if c_n[c] > 0:
                        c_n[c] -= 1
                    else:
                        is_in = False
                        break
                else:
                    is_in = False
                    break
            if is_in:
                result += len(word)
            else:
                continue
        return result
