class Solution(object):

    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        i = 0
        j = len(people) - 1
        result = 0
        people.sort()

        while i <= j:
            result += 1
            if people[i] + people[j] <= limit:
                i += 1
            j -= 1

        return result
            
        
                
        
        
        
        
        
