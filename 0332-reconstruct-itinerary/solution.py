class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        
        n = len(tickets)
        from collections import defaultdict
        airportMap = defaultdict(list)
        airportIdx = dict()
        
        for i in xrange(len(tickets)):
            start, end = tickets[i][0], tickets[i][1]
            
            # if start not in airportMap:
            #     airportMap[start] = []
            airportMap[start].append(end)
            
        for airport, itinerary in airportMap.items():
            itinerary.sort()
            airportIdx[airport] = [False]*len(itinerary)
        
        # print(airportMap)
        # print(airportIdx)
        
        self.result = []
        
        def visitAirports(start, route):
            if len(route) == n+1:
                self.result = copy.deepcopy(route)
                # print("result ", self.result)
                return True
            
            for i, dest in enumerate(airportMap[start]):
                if not airportIdx[start][i]:
                    airportIdx[start][i] = True
                    route = route + [dest]
                    ret = visitAirports(dest, route)
                    airportIdx[start][i] = False
                    
                    if ret:
                        return True
                    else:
                        route.pop()
            return False
                        
        route = ["JFK"]
        visitAirports("JFK", route)        
        return self.result
            
