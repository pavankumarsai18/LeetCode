class Solution {
    vector<vector<string>> dic={{"0","1","8"},
                                {"00", "11","69","88","96"}};
    
    vector<string> findStrobogrammatic(int n) {
        if(n==1)return {"0","1","8"};
        if(n==2)return {"11","69","88","96"};
        
        vector<string> out;

        if(n%2!=0){
            // if n is odd find n-1 first
            vector<string> tmp=findStrobogrammatic(n-1);
            for(string str:tmp){
                if(str[0]=='0')continue;
                for(string t:dic[0]){
                    // insert single digits in middle of numbers of length n-1
                    string s=str;
                    out.push_back(s.insert(str.size()/2, t));
                }
            }
        }else{
            // if n is even find n-2 first
            vector<string> tmp=findStrobogrammatic(n-2);
            for(string str:tmp){
                if(str[0]=='0')continue;
                for(string t:dic[1]){
                    // insert two digits in middle of numbers of length n-2
                    string s=str;
                    out.push_back(s.insert(str.size()/2, t));
                }
            }
        }
        return out;
    }    
public:
    int strobogrammaticInRange(string low, string high) {
        int count=0;
        long lown=stol(low);
        long highn=stol(high);
        
        for(int n=low.size();n<=high.size();n++){
            for(string num:findStrobogrammatic(n)){
                long numn=stol(num);
                if(lown<=numn && numn<=highn)count++;
            }
        }
        return count;
    }
};
