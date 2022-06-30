class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:            
        def getKey(log: str)-> tuple:
            logID, contents = log.split(" ", maxsplit=1)
            return (0, contents, logID) if contents[0].isalpha() else (1,)
        
        return sorted(logs, key=getKey)
            
            
        
