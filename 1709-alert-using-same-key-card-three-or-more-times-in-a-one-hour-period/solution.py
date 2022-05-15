class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        
        def getDiff(t2, t1):
            h1, m1 = int(t1[:2]), int(t1[3:])
            h2, m2 = int(t2[:2]), int(t2[3:])
            return (h2 - h1)*60 + (m2 - m1)
            
        
        nameTimeMap = dict()
        
        n = len(keyName)
        
        for i in range(n):
            name = keyName[i]
            if name not in nameTimeMap:
                nameTimeMap[name] = []
            nameTimeMap[name].append(keyTime[i])
        
        window = 3
        
        result = []
        for name, times in nameTimeMap.items():
            times.sort()
            i = 0
            
            while i <= len(times) - window:
                start = i
                j = i + 1
                alerted = True
                while j < window + i:
                    if getDiff(times[j], times[start]) > 60:
                        alerted = False
                        break
                    j += 1
                if alerted:
                    result.append(name)
                    break
                i += 1
        return sorted(result)
                    
