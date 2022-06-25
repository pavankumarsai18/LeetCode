class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        
        supplySet: set[str] = set(supplies)
            
        indegree: dict[str, int]  = {recipe: 0 for recipe in recipes}
            
        adjList:  dict[str, list] = defaultdict(list)
        
        for i, recipe in enumerate(recipes):
            for ingredient in ingredients[i]:
                if ingredient not in supplySet:
                    adjList[ingredient].append(recipe)
                    indegree[recipe] += 1
        
        
        q = collections.deque([])
        ans:list[str] = []
            
        for recipie, degree in indegree.items():
            if degree == 0:
                q.append(recipie)
        
        while q:
            recipe = q.popleft()
            ans.append(recipe)
            
            for neigh in adjList[recipe]:
                indegree[neigh] -= 1
                if indegree[neigh] == 0:
                    q.append(neigh)
        return ans
                
