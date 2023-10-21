class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        cur_string = s

        while True:
            index = cur_string.find(part)
            if index != -1:
                cur_string = cur_string[:index] + cur_string[index + len(part):]
            else:
                return cur_string
        return ""            
