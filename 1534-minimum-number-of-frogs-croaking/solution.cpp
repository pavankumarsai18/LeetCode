class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
     
        // maximum number of simultaneous creaks = min number of frogs
        
        int c, r, o, a, k;
        c = r = o = a = k = 0;
        
        int ans = 0;
        int minFrogs = 0;
        
        for(int i = 0; i < croakOfFrogs.size(); i++)
        {
            switch(croakOfFrogs[i])
            {
                case 'c':{
                    c++;
                    break;
                }
                case 'r':{
                    r++;
                    if(r > c) return -1;
                     break;
                }
                case 'o':{
                    o++;
                    if(o > r) return -1;
                     break;
                }    
                case 'a':{
                    a++;
                    if(a > o) return -1;
                     break;
                }
                case 'k': {
                    k++;
                    if(k > a) return -1;
                    
                    
                    minFrogs = max({minFrogs, c, r, o, a, k});
                    
                    c--; r--; o--; a--; k--;
                    break;
                }                
            }
        }
        
        if(c || r || o || a || k) return -1;
        
        return minFrogs;
        
    }
};
