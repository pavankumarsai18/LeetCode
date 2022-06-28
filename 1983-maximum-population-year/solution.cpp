class Solution 
{
public:
    int maximumPopulation(vector<vector<int>>& logs)
    {
        const int n = logs.size();
        vector<int> birthYears(n,0) , deathYears(n,0);
        
        for(int i = 0; i < n; i++)
        {
            birthYears[i] = logs[i][0];
            deathYears[i] = logs[i][1];
        }
        
        sort(birthYears.begin(), birthYears.end());
        sort(deathYears.begin(), deathYears.end());
        
        int birthIndex, deathIndex, maxPopulation, minYear, numAlive;
        
        birthIndex = deathIndex = maxPopulation = numAlive = minYear = 0;
        
        
        while(birthIndex < n)
        {
            if(birthYears[birthIndex] < deathYears[deathIndex])
            {
                numAlive++;
                if(numAlive > maxPopulation)
                {
                    maxPopulation = numAlive;
                    minYear = birthYears[birthIndex];
                }
                birthIndex++;
            }
            else
            {
                numAlive--;
                deathIndex++;
            }
            
        }
        
        return minYear;
    }
};
