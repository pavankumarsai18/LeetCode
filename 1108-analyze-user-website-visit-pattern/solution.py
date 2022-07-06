class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        user_to_website = defaultdict(list)
        for i, user in enumerate(username):
            user_to_website[user].append((timestamp[i], website[i]))
        
        pattern_to_user = defaultdict(set)
        
        
        for user, websites in user_to_website.items():
            n = len(websites)
            if n < 3:
                continue
            
            websites.sort()
            websiteNames = [website[1] for website in websites]
            
            for i in range(n - 2):
                for j in range(i+1, n - 1):
                    for k in range(j+1, n):
                        pattern = (websiteNames[i], websiteNames[j], websiteNames[k])
                        pattern_to_user[pattern].add(user)
            
        bucket = defaultdict(list)
        max_frequency = 0
        for pattern, users in pattern_to_user.items():
            bucket[len(users)].append(pattern)
            if max_frequency < len(users):
                max_frequency = len(users)
            
        return sorted(bucket[max_frequency])[0]
        
            
            
            
